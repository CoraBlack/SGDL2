#ifndef SPRITE_H
#define SPRITE_H

#include "../Platform.h"

#ifdef WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif // WIN32

#ifdef LINUX
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#endif

#include <string>
#include "Asset.h"

#define Uint unsigned int

typedef enum Anchors{
	LEFT_TOP  ,		// 左上
	MIDDLE_TOP,		// 中上
	RIGHT_TOP ,		// 右上
	LEFT_MIDDLE ,	// 正左
	MIDDLE	    ,	// 正中
	RIGHT_MIDDLE,	// 正右
	LEFT_BOTTOM  ,	// 左下
	MIDDLE_BOTTOM,	// 中下
	RIGHT_BOTTOM ,	// 右下
}Anchors;	//锚点类型

class Sprite : protected Asset{
public:
	Sprite(std::string &path, Uint w, Uint h);
	~Sprite();

public:
	std::string GetPath() const;							  // 获取图像路径
	int ChangePath(std::string &path, Uint w, Uint h);		  //修改图像路径
	int SetZoom(float z);									  // 设置图像缩放比

public:
	Uint weight, height = 0; // 图像的宽高

private:
	float zoom = 1.0f;		 // 图像缩放 
	Anchors anchors = MIDDLE;// 图像锚点
};

#endif