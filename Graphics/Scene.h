#ifndef SCENE_H
#define SCENE_H

#include "../Platform.h" 

#ifdef WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif // WIN32

#ifdef LINUX
#include <SDL2/SDL.h>
#endif

#include "Camera.h"

class Scene{
public:
	Scene();
	~Scene();

public:
	virtual void Show();

private:
	//Camera* camera = nullptr;
	//SDL_Window* window = nullptr;
};

#endif