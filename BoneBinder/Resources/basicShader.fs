#version 330 core

uniform sampler2D tex;
uniform vec4 DiffuseColor;
uniform mat4 WorldOnly;
uniform mat4 WorldInverseTranspose;
uniform vec3 EyePosition;
uniform int SpecularPower;
uniform vec3 EmissiveColor;
uniform vec3 SpecularColor;

uniform vec3 DirLight0Direction;
uniform vec3 DirLight0DiffuseColor;
uniform vec3 DirLight0SpecularColor;
uniform vec3 DirLight1Direction;
uniform vec3 DirLight1DiffuseColor;
uniform vec3 DirLight1SpecularColor;
uniform vec3 DirLight2Direction;
uniform vec3 DirLight2DiffuseColor;
uniform vec3 DirLight2SpecularColor;

in vec4 diffuseO;
in vec2 texcoordO;
in vec3 positionWSO;
in vec3 normalWSO;

out vec4 colorOutput;

void main()
{
	vec4 color = texture(tex, texcoordO) * diffuseO;

	vec3 eyeVector = normalize(EyePosition - positionWSO);

	mat3 lightDirections = mat3(0);
	mat3 lightDiffuse = mat3(0);
	mat3 lightSpecular = mat3(0);
	mat3 halfVectors = mat3(0);

	for (int i = 0; i < 3; i++)
	{
		lightDirections[i] = mat3(DirLight0Direction, DirLight1Direction, DirLight2Direction)[i];
		lightDiffuse[i] = mat3(DirLight0DiffuseColor, DirLight1DiffuseColor, DirLight2DiffuseColor)[i];
		lightSpecular[i] = mat3(DirLight0SpecularColor, DirLight1SpecularColor, DirLight2SpecularColor)[i];

		halfVectors[i] = normalize(eyeVector - lightDirections[i]);
	}

	vec3 dotL = -lightDirections * normalWSO;
	vec3 dotH = halfVectors * normalWSO;

	vec3 zeroL = step(0, dotL);

	vec3 diffuse = zeroL * dotL;
	vec3 specular = pow(max(dotH, 0) * zeroL, vec3(SpecularPower));

	vec3 finalLightDiffuse = (vec3(diffuse) * lightDiffuse) * vec3(DiffuseColor) + EmissiveColor;
	vec3 finalLightSpecular = (specular * lightSpecular) * SpecularColor;

	color.rgb *= finalLightDiffuse;

	color.rgb += finalLightSpecular * color.a;

	colorOutput = color;
}