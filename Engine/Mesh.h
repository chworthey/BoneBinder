#pragma once

#include "EngineDLL.h"
#include <memory>
#include <vector>
#include "Vertex.h"
#include <GL/glew.h>

class Mesh
{
private:
	enum VertexBuffers
	{
		POSITION_VERTEX_BUFFER,

		NUM_VERTEX_BUFFERS
	};

	GLuint mVertexArrayObject;
	GLuint mVertexBufferObjects[NUM_VERTEX_BUFFERS];
	unsigned int mDrawCount;

public:
	 void Initialize(Vertex *vertices, unsigned int numVertices);
	 Mesh() {}
	 ~Mesh();

	void Draw() const;

private:
	Mesh(const Mesh &other);
	void operator=(const Mesh &other) {}
};

