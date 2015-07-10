#include "Rectangle.h"

#include "Assert.h"

Rectangle::Rectangle()
: mLeft(0.0f),
mTop(0.0f),
mRight(0.0f),
mBottom(0.0f)
{
}


Rectangle::Rectangle(float left, float top, float right, float bottom)
: mLeft(left),
mTop(top),
mRight(right),
mBottom(bottom)
{
	Assert(right >= left && bottom >= top, "Rectangle dimensions.");
}

Rectangle::~Rectangle()
{
}

glm::vec2 Rectangle::CalculateCenter() const
{
	return glm::vec2((mLeft + mRight) / 2.0f, (mTop + mBottom) / 2.0f);
}

glm::vec2 Rectangle::CalculateSize() const
{
	return glm::vec2(mRight - mLeft, mBottom - mTop);
}
