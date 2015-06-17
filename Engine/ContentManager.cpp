#include "ContentManager.h"
#include "Model.h" 
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

ContentManager::ContentManager(ShaderManager &shaderManager)
: mShaderManager(shaderManager)
{
}

ContentManager::~ContentManager()
{
}

ENGINE_API std::vector<Model> ContentManager::LoadModelsFromFile(std::string path) const
{
	std::vector<Model> models;

	Assimp::Importer importer;

	const aiScene *scene = importer.ReadFile(path,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);

	if (!scene)
	{
		throwLoadException(importer.GetErrorString());
	}

	if (!scene->mMeshes || scene->mNumMeshes <= 0)
	{
		throwLoadException("No meshes found.");
	}

	for (unsigned int n = 0; n < scene->mNumMeshes; n++)
	{
		aiMesh *mesh = scene->mMeshes[n];

		if (!mesh)
		{
			throwLoadException("Empty mesh.");
		}

		std::string meshName = std::string(mesh->mName.C_Str());

		if (!mesh->HasFaces())
		{
			throwLoadException("Mesh " + meshName + " has no faces.");
		}

		if (!mesh->HasPositions())
		{
			throwLoadException("Mesh " + meshName + " has no positions.");
		}

		if (!mesh->HasNormals())
		{
			throwLoadException("Mesh " + meshName + " has no normals.");
		}

		Model model;

		models.push_back(model);
	}

	return models;
}

Shader ContentManager::LoadShaderFromFile(std::string path) const
{
	return Shader(path, mShaderManager);
}

void ContentManager::throwLoadException(std::string message) const
{
	ContentLoadException e(message);
	throw e;
}

ContentLoadException::ContentLoadException(std::string errorMsg)
: EngineException("Content Load", errorMsg)
{
}