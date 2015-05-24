// DisplayWindow.cpp 
// compile with: cl /EHsc DisplayWindow.cpp /link Engine.lib

#include "DisplayWindow.h"
#include <GL/glew.h>
#include <iostream>

DisplayWindow::DisplayWindow(int width, int height, const std::string &title) 
	: mWindow(), 
	mIsClosed(false)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
		SDL_WINDOW_OPENGL);
	mGLContext = SDL_GL_CreateContext(mWindow);

	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize!" << std::endl;
	}
}


DisplayWindow::~DisplayWindow()
{
	SDL_GL_DeleteContext(mGLContext);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void DisplayWindow::SwapBuffers()
{
	SDL_GL_SwapWindow(mWindow);
}

void DisplayWindow::UpdateClosed()
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			mIsClosed = true;
		}
	}
}