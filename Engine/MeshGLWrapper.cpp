#include "MeshGLWrapper.h"
#include "Assert.h"

void MeshGLWrapper::Initialize(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices)
{
	mVertexCount = (unsigned int) vertices.size();
	mIndexCount = (unsigned int)indices.size();

	Assert(mVertexCount > 0, "No vertices.");
	Assert(mIndexCount > 0, "No indices.");

	glGenVertexArrays(1, &mVertexArrayObject);
	glBindVertexArray(mVertexArrayObject);

	glGenBuffers(NUM_VERTEX_BUFFERS, mVertexBufferObjects);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObjects[POSITION_VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, mVertexCount * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(POSITION_VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), 0);

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObjects[COLOR_VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, mVertexCount * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(COLOR_VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void *)sizeof(glm::vec3));

	glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferObjects[TEXTURE_COORD_VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, mVertexCount * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(TEXTURE_COORD_VERTEX_BUFFER, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), (void *)(sizeof(glm::vec3) * 2));

	glGenBuffers(1, &mIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(POSITION_VERTEX_BUFFER);
	glEnableVertexAttribArray(COLOR_VERTEX_BUFFER);
	glEnableVertexAttribArray(TEXTURE_COORD_VERTEX_BUFFER);
	glBindVertexArray(0);
}

MeshGLWrapper::~MeshGLWrapper()
{
	glDeleteVertexArrays(1, &mVertexArrayObject);
}

void MeshGLWrapper::Draw() const
{
	glBindVertexArray(mVertexArrayObject);

	glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, (void *)0);

	glBindVertexArray(0);
}