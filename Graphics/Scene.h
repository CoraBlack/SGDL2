#ifndef SCENE_H
#define SCENE_H

#include <SDL.h>
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