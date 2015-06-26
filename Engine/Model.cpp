#include "Model.h"

Model::Model()
{

}

Model::~Model()
{
}

const std::vector<std::shared_ptr<MeshGLWrapper>> & Model::GetMeshes() const
{
	return mMeshes;
}

void Model::AddMesh(std::shared_ptr<MeshGLWrapper> mesh)
{
	mMeshes.push_back(mesh);
}
