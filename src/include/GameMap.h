#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <map>
#include "BaseObject.h"
#include "Sprite.h"
#include "Actor.h"

class GameMap : public BaseObject{
public:
    GameMap() = default;
    ~GameMap() = default;

    void AddActor(Actor* new_obj, int x, int y);
private:
    Sprite* background = nullptr;   //地图背景

    std::vector<
    std::vector<
    std::vector<Actor*>
    >> Cells; //地图的区块[x][y][Actors]
    
    int cell_size = 128;//区块大小为128像素
};


#endif // GAMEMAP_H