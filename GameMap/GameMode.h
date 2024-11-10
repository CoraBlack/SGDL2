#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "../Graphics/Camera.h"
#include "../GameObject/Charactor.h"


class GameMode {
public:


private:
	Charactor* playerTarget = nullptr;
	Camera*    camera	    = nullptr;		

public:
	inline Camera* GetCamera() const {
		return this->camera;
	}
};

#endif