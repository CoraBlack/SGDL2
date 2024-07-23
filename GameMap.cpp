#include "include/GameMap.h"

void GameMap::AddActor(Actor* new_obj, int x, int y){
    //检查对象存入位置在x上是否越界,若越界，则：
    if(x/cell_size > this->Cells.size()){
        Cells.resize(x/cell_size);
    }

    //检查对象存入位置在y上是否越界,若越界，则：
    if(y/cell_size > this->Cells[x/cell_size][y/cell_size].size()){
        Cells[x/cell_size].resize(y/cell_size);
    }

    //将对象存入位置
    Cells[x/cell_size][y/cell_size].push_back(new_obj);

    return;
}