#include "Shader.h"
#include <fstream>
#include <iostream>


Shader::Shader(const std::string& fileName, ShaderManager &shaderManager)
: mShaderManager(shaderManager)
{
	mFileName = fileName;

	mProgram = glCreateProgram();
	mShaders[VERTEX_SHADER] = createShader(loadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	mShaders[FRAGMENT_SHADER] = createShader(loadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

	for (auto shader : mShaders)
		glAttachShader(mProgram, shader);

	//glBindAttribLocation(mProgram, 0, "position");

	glLinkProgram(mProgram);
	checkShaderError(mProgram, GL_LINK_STATUS, true, "Program Linking failed: ");

	glValidateProgram(mProgram);
	checkShaderError(mProgram, GL_VALIDATE_STATUS, true, "Program validation failed: ");
}

void Shader::Bind()
{
	glUseProgram(mProgram);

	mShaderManager.SetCurrentShader(this);
}

Shader::~Shader()
{
	for (auto shader : mShaders)
	{
		glDetachShader(mProgram, shader);
		glDeleteShader(shader);
	}

	glDeleteProgram(mProgram);
}

void Shader::SetModelViewProjectionMatrixUniform(glm::mat4 mvp)
{
	GLuint uniformLocation = glGetUniformLocation(mProgram, "MVP");
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &mvp[0][0]);
}


void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMesage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		ShaderException e(mFileName, errorMesage + std::string(error));
		throw e;
	}
}

std::string Shader::loadShader(const std::string &fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		ShaderException e(fileName, "Unable to read.");
		throw e;
	}

	return output;
}

GLuint Shader::createShader(const std::string &fullText, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0)
	{
		ShaderException e(mFileName, "Shader creation failed.");
		throw e;
	}

	const GLchar *shaderSourceStrings[1];
	GLint shaderSourceStringLengths[1];

	shaderSourceStrings[0] = fullText.c_str();
	shaderSourceStringLengths[0] = (GLint)fullText.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
	glCompileShader(shader);

	checkShaderError(shader, GL_COMPILE_STATUS, false, "Shader compilation failed: ");

	return shader;
}

ShaderException::ShaderException(std::string fileName, std::string errorMsg)
: EngineException("Shader", "File name: " + fileName + " Message: " + errorMsg)
{
}