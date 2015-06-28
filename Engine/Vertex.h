#pragma once

#include <glm/glm.hpp>

class Vertex
{
private:
	glm::vec3 mPosition;
	glm::vec3 mColor;
	glm::vec2 mTextureCoords;
	glm::vec3 mNormal;

public:
	Vertex();
	Vertex(const glm::vec3 &position, const glm::vec3 &color, const glm::vec2 &textureCoords, const glm::vec3 &normal);
	~Vertex();

	const glm::vec3 &GetPosition() const;
	const glm::vec3 &GetColor() const;
	const glm::vec2 &GetTextureCoords() const;
	const glm::vec3 &GetNormal() const;
};

