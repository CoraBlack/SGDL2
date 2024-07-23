#include "include/Camera.h"

Camera::Camera(SDL_Window* window){
    /*初始化Camera,,明确附属关系*/
    this-> window = window;
    return;
}

Camera::~Camera(){
    SDL_DestroyRenderer(this->renderer);
    return;
}

void Camera::On_Enter(){
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    return;
}

void Camera::On_Exit(){
    SDL_DestroyRenderer(this->renderer);
    return;
}

void Camera::Update(){
    while(1){
        SDL_RenderPresent(this->renderer);
        SDL_Delay(1/fps * 1000);
        SDL_RenderClear(this->renderer);
    }
}