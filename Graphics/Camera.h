#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>
#include "Scene.h"

class Camera{
public:
	Camera() = default;
	~Camera() = default;

public:
	int OnEnter();
	int OnExit();

private:
	int index = -1;
	Uint32 flags = SDL_RENDERER_ACCELERATED;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	
public:
	inline SDL_Renderer* GetRenderer() { return this->renderer; }
};

#endif