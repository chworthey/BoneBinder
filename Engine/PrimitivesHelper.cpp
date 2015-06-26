#include "PrimitivesHelper.h"

#include "Vertex.h"
#include <vector>
#include <memory>

//    1
//   / \
//  /   \
// 3-----2
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

// 1--2
// | /|
// |/ |
// 4--3
Model PrimitivesHelper::CreateQuad(Vertex a, Vertex b, Vertex c, Vertex d)
{
	Model quadModel;
	std::shared_ptr<MeshGLWrapper> quadMesh = std::shared_ptr<MeshGLWrapper>(new MeshGLWrapper());

	std::vector<Vertex> vertices;
	vertices.push_back(a);
	vertices.push_back(b);
	vertices.push_back(c);
	vertices.push_back(d);

	std::vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(3);
	indices.push_back(1);
	indices.push_back(2);

	quadMesh->Initialize(vertices, indices);
	quadModel.AddMesh(quadMesh);

	return quadModel;
}
