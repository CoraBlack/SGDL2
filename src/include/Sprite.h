#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL2/SDL_image.h>
#include "BaseObject.h"
#include "Scene.h"

class Sprite : public BaseObject
{
private:
    typedef struct Texture{
        SDL_Surface* surface;
        SDL_Rect rect;
        SDL_Texture* texture;
        std::string path;
    }Texture;                 //贴图类

public:
    //构造函数
    Sprite(std::string path   /*图像文件路径*/,
            int x             /*图像的宽*/,
            int y             /*图像的高*/,
            IMG_InitFlags flag/*图像的初始化类型*/
            );
    
    //析构函数
    ~Sprite();

    void LoadTexture(std::string path);     //将texture加载到内存
    void ReleaseTexture();                  //释放texture的内存
    void AddToScene(Scene* scene);          //添加图像到目标渲染器
    void EraseFromScene(Scene* scene);      //擦除图像从目标渲染器
    Texture GetTexture();                   //获取texture对象

private:
    Texture texture;            
};

#endif