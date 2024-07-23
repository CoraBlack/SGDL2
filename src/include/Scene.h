#ifndef SCENE_H
#define SCENE_H 

#include <string>
#include <SDL2/SDL.h>
#include "BaseObject.h"
#include "Camera.h"

class Scene : public BaseObject{
public:
    Scene(
        SDL_WindowFlags win_flag,            //窗口模式
        std::string win_title = "New Window",//窗口标签，默认为"New Window"
        int win_x = SDL_WINDOWPOS_CENTERED,  //窗口位置x，默认为屏幕中心
        int win_y = SDL_WINDOWPOS_CENTERED,  //窗口位置y，默认为屏幕中心
        int win_w = 800,                     //窗口像素x，默认为800
        int win_h = 600                      //窗口像素y，默认为600
    );
    ~Scene();

    virtual int OnEnter();      //显示窗口
    virtual int OnExit();       //退出窗口

private:
    SDL_Window* scene = nullptr;                 //视窗指针对象
    SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE;//视窗模式
    Camera* camera = nullptr;                    //视窗摄像机
    const char* title = "New Window";            //视窗标签

    int x = SDL_WINDOWPOS_CENTERED,              //视窗位置x
        y = SDL_WINDOWPOS_CENTERED,              //视窗位置y
        w = 800,                                 //视窗宽
        h = 600;                                 //视窗高
};

#endif // SENCE_H