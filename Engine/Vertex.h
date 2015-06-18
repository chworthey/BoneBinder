#pragma once

#include <glm/glm.hpp>

class Vertex
{
private:
	glm::vec3 mPosition;
	glm::vec3 mColor;

public:
	Vertex();
	Vertex(const glm::vec3 &position, const glm::vec3 &color);
	~Vertex();

	const glm::vec3 &GetPosition() const;
	const glm::vec3 &GetColor() const;
};

