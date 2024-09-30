#ifndef  GAME_MAP_H
#define  GAME_MAP_H

#include <map>
#include <vector>
#include "../GameObject/Actor.h"
#include "../Vector2.h"

class GameMap{
public:
	GameMap()  = default;
	~GameMap() = default;

public:
	void Insert(Actor* newActor);
	void Remove(Actor* actor);
	void SetBlockSize(int& size);

private:
	int blockSize = 128;
	std::map<Vector2, std::vector<Actor*>>blockMap;
};


#endif // !
