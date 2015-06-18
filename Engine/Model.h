#pragma once

#include "EngineDLL.h"
#include "MeshGLWrapper.h"
#include <memory>
#include <vector>
#include "glm/glm.hpp"

class Model
{
private:
	std::vector<std::shared_ptr<MeshGLWrapper>> mMeshes;
public:
	ENGINE_API Model();
	ENGINE_API ~Model();

	const std::vector<std::shared_ptr<MeshGLWrapper>> &GetMeshes() { return mMeshes; }

	void AddMesh(std::shared_ptr<MeshGLWrapper> mesh);
};