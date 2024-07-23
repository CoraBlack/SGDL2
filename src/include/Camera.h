#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include "BaseObject.h"

class Camera : public BaseObject{
public:
    Camera(SDL_Window* window);
    ~Camera();

    void On_Enter();
    void On_Exit();
    void Update();

private:
    int fps = 60;       //相机的更新帧数
    int located_x = 0;  //相机的场景位置x
    int located_y = 0;  //相机的场景位置y
    float zoom = 1.0f;  //缩放大小
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#endif // CAMERA_H