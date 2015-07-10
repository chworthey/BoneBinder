#pragma once

#include "EngineDLL.h"
#include "glm/glm.hpp"

struct Rectangle
{
private:
	float mLeft, mTop, mRight, mBottom;

public:
	ENGINE_API Rectangle();
	ENGINE_API Rectangle(float left, float top, float right, float bottom);
	ENGINE_API ~Rectangle();
	ENGINE_API glm::vec2 CalculateCenter() const;
	ENGINE_API glm::vec2 CalculateSize() const;
	ENGINE_API glm::vec2 GetLeftTop() const { return glm::vec2(mLeft, mTop); }
	ENGINE_API glm::vec2 GetRightBottom() const { return glm::vec2(mRight, mBottom); }
	ENGINE_API float GetWidth() const { return mRight - mLeft; }
	ENGINE_API float GetHeight() const { return mBottom - mTop; }

	ENGINE_API float GetLeft() const { return mLeft; }
	ENGINE_API void SetLeft(float val) { mLeft = val; }
	ENGINE_API float GetTop() const { return mTop; }
	ENGINE_API void SetTop(float val) { mTop = val; }
	ENGINE_API float GetRight() const { return mRight; }
	ENGINE_API void SetRight(float val) { mRight = val; }
	ENGINE_API float GetBottom() const { return mBottom; }
	ENGINE_API void SetBottom(float val) { mBottom = val; }
};

