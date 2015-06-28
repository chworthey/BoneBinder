#include "Vertex.h"


Vertex::Vertex()
: mPosition(0.0f, 0.0f, 0.0f),
mColor(0.0f, 0.0f, 0.0f),
mTextureCoords(0.0f, 0.0f),
mNormal(0.0, 0.0, 1.0)
{
}

Vertex::Vertex(const glm::vec3 &position, const glm::vec3 &color, const glm::vec2 &textureCoords, const glm::vec3 &normal)
: mPosition(position),
mColor(color),
mTextureCoords(textureCoords),
mNormal(normal)
{
}

Vertex::~Vertex()
{
}

const glm::vec3 & Vertex::GetPosition() const
{
	return mPosition;
}

const glm::vec3 & Vertex::GetColor() const
{
	return mColor;
}

const glm::vec2 & Vertex::GetTextureCoords() const
{
	return mTextureCoords;
}

const glm::vec3 & Vertex::GetNormal() const
{
	return mNormal;
}
