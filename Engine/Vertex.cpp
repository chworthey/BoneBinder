#include "Vertex.h"


Vertex::Vertex()
: mPosition(0.0f, 0.0f, 0.0f),
mColor(0.0f, 0.0f, 0.0f)
{
}

Vertex::Vertex(const glm::vec3 &position, const glm::vec3 &color)
: mPosition(position),
mColor(color)
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
