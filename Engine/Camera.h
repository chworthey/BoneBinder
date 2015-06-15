#pragma once

#include "EngineDLL.h"
#include <glm/glm.hpp>
#include <memory>

class DisplayWindow;

class Camera
{
private:
	glm::vec3 mPosition;
	glm::vec3 mTarget;
	float mFOV;
	glm::mat4 mProjection;
	glm::mat4 mView;
	DisplayWindow &mWindow;

public:
	ENGINE_API Camera(glm::vec3 position, glm::vec3 targetPosition, float fieldOfView, DisplayWindow &window);
	ENGINE_API ~Camera();
	ENGINE_API void SetPosition(glm::vec3 position);
	ENGINE_API glm::vec3 GetPosition() const;
	ENGINE_API void SetTargetPosition(glm::vec3 targetPosition);
	ENGINE_API glm::vec3 GetTargetPosition() const;
	ENGINE_API void SetFieldOfView(float fieldOfView);
	ENGINE_API float GetFieldOfView() const;

	ENGINE_API glm::mat4 GetProjectionMatrix() const;
	ENGINE_API glm::mat4 GetViewMatrix() const;

private:
	void updateVPMatrices();
};

