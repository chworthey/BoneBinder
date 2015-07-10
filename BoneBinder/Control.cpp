#include "Control.h"

#include "Renderer.h"
#include "Texture2D.h"

Control::Control(Texture2D &controlElements, Renderer &renderer)
: mControlElements(controlElements),
mRenderer(renderer)
{
}


Control::~Control()
{
}

const int kControlElementSize = 64;

Rectangle Control::GetSourceArea(int xIndex, int yIndex)
{
	float left = (float)xIndex * kControlElementSize;
	float top = (float)yIndex * kControlElementSize;
	return Rectangle(left, top, left + kControlElementSize, top + kControlElementSize);
}
