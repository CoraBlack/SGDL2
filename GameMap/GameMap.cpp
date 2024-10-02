#include "GameMap.h"

void GameMap::Insert(Actor* newActor) {
	// 新对象所在的区块位置
	Vector2 pos = { newActor->GetPos().x/this->blockSize,
				    newActor->GetPos().y/this->blockSize
	};

	if (this->blockMap.find(pos) == this->blockMap.end()) {
		// 目标区块不存在，创建一个新区块
		this->blockMap.insert(std::pair<Vector2, std::vector<Actor*>>(pos, std::vector<Actor*>({ newActor })));
	}
	else {
		// 目标区块存在，向区块中添加新对象
		this->blockMap[pos].push_back(newActor);
	}

	return;
}

void GameMap::Remove(Actor* actor) {
	// 对象所在的区块位置
	Vector2 pos = { actor->GetPos().x / (long double)this->blockSize,
					actor->GetPos().y / (long double)this->blockSize
	};

	
}

void GameMap::SetBlockSize(int& size) {
	this->blockSize = size;
}

void GameMap::Update() {

}
