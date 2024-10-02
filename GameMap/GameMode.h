#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "../Graphics/Camera.h"
#include "../GameObject/Charactor.h"


class GameMode {
public:


private:
	Charactor* playerClass = nullptr; //玩家类
	Camera* camera = new Camera;	  //摄像机类
};

#endif