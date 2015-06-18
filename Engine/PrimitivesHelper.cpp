#include "PrimitivesHelper.h"

#include "Vertex.h"
#include <vector>
#include <memory>

Model PrimitivesHelper::CreateTriangle(Vertex a, Vertex b, Vertex c)
{
	Model triModel;
	std::shared_ptr<MeshGLWrapper> triMesh = std::shared_ptr<MeshGLWrapper>(new MeshGLWrapper());

	std::vector<Vertex> vertices;
	vertices.push_back(a);
	vertices.push_back(b);
	vertices.push_back(c);

	std::vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	triMesh->Initialize(vertices, indices);
	triModel.AddMesh(triMesh);

	return triModel;
}
