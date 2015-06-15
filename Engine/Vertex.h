#pragma once

#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex();
	Vertex(const glm::vec3 &position);
	~Vertex();

private:
	glm::vec3 mPosition;
	//glm::vec3 mColor;
};

