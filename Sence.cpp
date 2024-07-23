#include "include/Scene.h"

Scene::Scene(
        SDL_WindowFlags win_flag,
        std::string win_title,
        int win_x,
        int win_y,
        int win_w,
        int win_h)
{
    //Check Vedio Model is Init
    if(SDL_WasInit(SDL_INIT_VIDEO)){
        SDL_Init(SDL_INIT_VIDEO);
    }
    //Init all mumber var of Scene
    this->flags = win_flag;
    this->title = win_title.c_str();
    this->x = win_x;
    this->y = win_y;
    this->w = win_w;
    this->h = win_h;
    this->camera = new Camera(this->scene);
    return;
}

Scene::~Scene(){
    delete this->camera;
    SDL_DestroyWindow(this->scene);
}


int Scene::OnEnter(){
    this->scene = SDL_CreateWindow(this->title, this->x, this->y, this->w, this->h, this->flags);
    this->camera->On_Enter();
    return 0;
}

int Scene::OnExit(){
    SDL_DestroyWindow(this->scene);
    camera->On_Exit();
    return 0;
}