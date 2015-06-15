#include "Model.h"

Model::Model()
{

}

Model::~Model()
{
}

void Model::AddMesh(std::shared_ptr<Mesh> mesh)
{
	mMeshes.push_back(mesh);
}
