#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "include/BaseObject.h"


int BaseObject::ExitGame(){
    SDL_Quit();
    IMG_Quit();
    return 0;
}