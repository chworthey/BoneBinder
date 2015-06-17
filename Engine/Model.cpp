#include "Model.h"

Model::Model()
{

}

Model::~Model()
{
}

void Model::AddMesh(std::shared_ptr<MeshGLWrapper> mesh)
{
	mMeshes.push_back(mesh);
}
