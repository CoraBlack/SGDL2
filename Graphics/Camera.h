#ifndef CAMERA_H
#define CAMERA_H

#include "../Platform.h"

#ifdef WIN32
#include <SDL.h>
#endif // WIN32

#ifdef LINUX
#include <SDL/SDL.h>
#endif

#include "Scene.h"

class Camera{
public:
	Camera() = default;
	~Camera() = default;

public:
	int OnEnter();
	int OnExit();

private:
	
public:

};

#endif