#include "PrimitivesHelper.h"


Model PrimitivesHelper::CreateTriangle(glm::vec3 a, glm::vec3 b, glm::vec3 c)
{
	Model triModel;
	std::unique_ptr<Mesh> triMesh = std::unique_ptr<Mesh>(new Mesh());

	Vertex vertices[3];
	vertices[0] = Vertex(a);
	vertices[1] = Vertex(b);
	vertices[2] = Vertex(c);

	triMesh->Initialize(vertices, 3);
	triModel.AddMesh(std::move(triMesh));

	return triModel;
}
