#ifndef WINDOW_H
#define WINDOW_H

#include "../Platform.h"

#ifdef WIN32
#include <SDL.h>
#endif // WIN32

#ifdef LINUX
#include <SDL2/SDL.h>
#endif

#include <string>
#include "Scene.h"

class Window {
public:
	Window(std::string title,
			unsigned int locate_x,
			unsigned int locate_y,
			unsigned int size_x,
			unsigned int size_y,
			Uint32 flags
	);
	~Window() = default;

private:
	SDL_Window* win = nullptr;
	Scene* scene = nullptr;
};

#endif