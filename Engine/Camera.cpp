#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include "DisplayWindow.h"

const float kNearPlaneClippingDistance = 0.1f;
const float kFarPlaneClippingDistance = 1000.0f;
const glm::vec3 kUp(0.0f, 0.0f, 1.0f);

Camera::Camera(glm::vec3 position, glm::vec3 targetPosition, float fieldOfView, DisplayWindow &window)
: mPosition(position),
mTarget(targetPosition),
mFOV(fieldOfView),
mWindow(window)
{
	updateVPMatrices();
}

Camera::~Camera()
{
}

void Camera::SetPosition(glm::vec3 position)
{
	mPosition = position;
	updateVPMatrices();
}

glm::vec3 Camera::GetPosition() const
{
	return mPosition;
}

void Camera::SetTargetPosition(glm::vec3 targetPosition)
{
	mTarget = targetPosition;
	updateVPMatrices();
}

glm::vec3 Camera::GetTargetPosition() const
{
	return mTarget;
}

void Camera::SetFieldOfView(float fieldOfView)
{
	mFOV = fieldOfView;
	updateVPMatrices();
}

float Camera::GetFieldOfView() const
{
	return mFOV;
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	return mProjection;
}

glm::mat4 Camera::GetViewMatrix() const
{
	return mView;
}

void Camera::updateVPMatrices()
{
	mProjection = glm::perspective(mFOV, mWindow.GetApectPixelRatio(), kNearPlaneClippingDistance, kFarPlaneClippingDistance);
	mView = glm::lookAt(mPosition, mTarget, kUp);
}