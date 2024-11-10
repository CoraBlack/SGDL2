#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "Vector2.h"
#include "Asset/Sprite.h"

class Actor{
public:
	Actor(std::string& path, Uint w, Uint h); //ͨ������ͼ����Դ������Actor
	Actor (Sprite s);						  //ͨ��Sprite��Դ����Actor
	~Actor() = default;

private :
	Sprite* sprite   =  nullptr;
	Vector2 position = { 0.f,0.f };

public:
	inline Vector2 GetPos() const {
		return this->position;
	}
};

#endif