#pragma once

#include "EngineDLL.h"
#include <memory>
#include <vector>
#include "Vertex.h"
#include <GL/glew.h>

class MeshGLWrapper
{
private:
	enum VertexBuffers
	{
		POSITION_VERTEX_BUFFER,
		COLOR_VERTEX_BUFFER,
		TEXTURE_COORD_VERTEX_BUFFER,
		NORMAL_VERTEX_BUFFER,
		NUM_VERTEX_BUFFERS
	};

	GLuint mVertexArrayObject;
	GLuint mVertexBufferObjects[NUM_VERTEX_BUFFERS];

	GLuint mIndexBuffer;

	unsigned int mVertexCount;
	unsigned int mIndexCount;

public:
	 void Initialize(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);
	 MeshGLWrapper() {}
	 ~MeshGLWrapper();

	void Draw() const;

private:
	MeshGLWrapper(const MeshGLWrapper &other);
	void operator=(const MeshGLWrapper &other) {}
};