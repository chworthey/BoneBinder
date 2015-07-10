#pragma once

#include "IDrawable.h"
#include "IUpdateable.h"
#include "Rectangle.h"

class Texture2D;
class Renderer;

class Control : public IUpdateable, public IDrawable
{
private:
	Texture2D &mControlElements;
	Renderer &mRenderer;
public:
	Control(Texture2D &mControlElements, Renderer &renderer);
	~Control();

protected:
	Texture2D &GetControlElements() { return mControlElements; }
	Renderer &GetRenderer() { return mRenderer; }

	virtual void Update(const Time &engineTime) override {}
	virtual void Draw() override {}

	Rectangle GetSourceArea(int xIndex, int yIndex);
};

