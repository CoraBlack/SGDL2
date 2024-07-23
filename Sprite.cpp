#include "include/Sprite.h"

/*********************************
 * Sprite类构造函数
 * 返回值 void
 * 参数：
 *  1：std::string path: 图片路径
 *  2：int x: 图片在窗口中的x坐标
 *  3：int y: 图片在窗口中的y坐标
 *  4：IMG_InitFlags flag: 图片格式
 *  功能：初始化IMG模块
 *       初始化texture对象
 ********************************/
Sprite::Sprite(std::string path, int x, int y, IMG_InitFlags flag){
    /*初始化IMG模块*/
    switch(flag)
    {
        case IMG_INIT_JPG:
            if(SDL_WasInit(flag)){
                IMG_Init(flag);
            }
            break;

        case IMG_INIT_PNG:
            if(SDL_WasInit(flag)){
                IMG_Init(flag);
            }
            break;

        case IMG_INIT_TIF:
            if(SDL_WasInit(flag)){
                IMG_Init(flag);
            }
            break;

        case IMG_INIT_WEBP:
            if(SDL_WasInit(flag)){
                IMG_Init(flag);
            }
            break;
        default:
            break;
    }

    this->texture.path  = path;
    this->texture.rect.x = x;
    this->texture.rect.y = y;
    return;
}

/**************************************
 * Sprite类析构函数
 * 参数：无
 * 作用：释放Sprite中Texture的内存
 *************************************/
Sprite::~Sprite(){
    //释放surface和texture的内存 
    SDL_DestroyTexture(this->texture.texture);
    SDL_FreeSurface(this->texture.surface);
    return;
}


void Sprite::LoadTexture(std::string path){
    this->texture.surface = IMG_Load(path.c_str());      //将Texture加载到surface上
    return;
}

void Sprite::ReleaseTexture(){
    //释放surface和texture的内存 
    SDL_DestroyTexture(this->texture.texture);
    SDL_FreeSurface(this->texture.surface);
    return;
}

void Sprite::AddToScene(Scene *scene){
    
    return;
}

void Sprite::EraseFromScene(Scene *scene){
    
    return;   
}

Sprite::Texture Sprite::GetTexture(){
    return this->texture;
}