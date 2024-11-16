#ifndef FRAME_H
#define FRAME_H

#include <funtional>
#include "../Asset/Sprite.h"
template<class T>

class Frame{
public:
    Frame()  = default;
    ~Frame() = default;

    int AddKeyFunction();

private:
    std::function<void()>func;
    Sprite* farmeSprite = nullptr;
};

#endif
