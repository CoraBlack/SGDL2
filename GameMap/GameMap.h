#ifndef  GAME_MAP_H
#define  GAME_MAP_H

#include <map>
#include <vector>
#include "../Vector2.h"
#include "../GameObject/Actor.h"
#include "GameMode.h"

class GameMap{
public:
	GameMap()  = default;
	~GameMap() = default;

public:
	void Insert(Actor* newActor);
	void Remove(Actor* actor);
	void SetBlockSize(int& size);
	void Update();

private:
	int blockSize = 128;
	std::map<Vector2, std::vector<Actor*>>blockMap;
	GameMode gameMode;
};


#endif // !
