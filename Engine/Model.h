#pragma once

#include "EngineDLL.h"
#include "Mesh.h"
#include <vector>
#include "glm/glm.hpp"

class Model
{
private:
	std::vector<std::shared_ptr<Mesh>> mMeshes;
public:
	ENGINE_API Model();
	ENGINE_API ~Model();

	const std::vector<std::shared_ptr<Mesh>> &GetMeshes() { return mMeshes; }

	void AddMesh(std::shared_ptr<Mesh> mesh);
};