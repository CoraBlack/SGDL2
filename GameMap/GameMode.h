#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "../Graphics/Camera.h"
#include "../GameObject/Charactor.h"


class GameMode {
public:


private:
	Charactor* playerClass = nullptr; //�����
	Camera* camera = new Camera;	  //�������
};

#endif