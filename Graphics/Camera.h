#ifndef CAMERA_H
#define CAMERA_H

#include "Platform.h"

#ifdef WIN32
#include <SDL.h>
#endif // WIN32

#ifdef LINUX
#include <SDL2/SDL.h>
#endif

#include "Scene.h"
#include "Vector2.h"

class Camera{
public:
	Camera() = default;
	~Camera() = default;

public:
	int OnEnter();
	int OnExit();

private:
	Vector2 position = { 0.f, 0.f };

public:
	inline Vector2 GetPos() const {
		return this->GetPos();
	}

};

#endif