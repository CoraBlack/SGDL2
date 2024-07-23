#ifndef ACTOR_H
#define ACTOR_H

#include "BaseObject.h"
#include "Sprite.h"

class Actor : public BaseObject{
public:
    Actor(Sprite* add_sprite);
    ~Actor();

private:
    Sprite* sprite;
};

#endif // ACTOR_H