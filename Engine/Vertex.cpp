#include "Vertex.h"


Vertex::Vertex()
: mPosition(0.0f, 0.0f, 0.0f)
{
}

Vertex::Vertex(const glm::vec3 &position)
: mPosition(position)
{
}

Vertex::~Vertex()
{
}
