#include "Mesh.h"
#include "Assert.h"

void Mesh::Initialize(Vertex *vertices, unsigned int numVertices)
{
	Assert(vertices);

	mDrawCount = numVertices;

	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	glGenBuffers(NUM_VERTEX_BUFFERS, mVertexBufferObjects);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObjects[POSITION_VERTEX_BUFFER]);

	glBufferData(GL_ARRAY_BUFFER, mDrawCount * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &mVertexArrayObject);
}

void Mesh::Draw() const
{
	glBindVertexArray(mVertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, mDrawCount);

	glBindVertexArray(0);
}
