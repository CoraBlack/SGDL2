#include "GameMap.h"

void GameMap::Insert(Actor* newActor) {
	// �¶������ڵ�����λ��
	Vector2 pos = { newActor->GetPos().x/this->blockSize,
				    newActor->GetPos().y/this->blockSize
	};

	if (this->blockMap.find(pos) == this->blockMap.end()) {
		// Ŀ�����鲻���ڣ�����һ��������
		this->blockMap.insert(std::pair<Vector2, std::vector<Actor*>>(pos, std::vector<Actor*>({ newActor })));
	}
	else {
		// Ŀ��������ڣ�������������¶���
		this->blockMap[pos].push_back(newActor);
	}

	return;
}

void GameMap::Remove(Actor* actor) {
	// �������ڵ�����λ��
	Vector2 pos = { actor->GetPos().x / (long double)this->blockSize,
					actor->GetPos().y / (long double)this->blockSize
	};

	
}

void GameMap::SetBlockSize(int& size) {
	this->blockSize = size;
}

void GameMap::Update() {

}
