#ifndef SPRITE_H
#define SPRITE_H

#include "../Platform.h"

#ifdef WIN32
#include <SDL.h>
#include <SDL_image.h>
#endif // WIN32

#ifdef LINUX
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include <vector>
#include <string>
#include "Asset.h"

#define Uint unsigned int

// 锚点类型，通过不同的锚点去显示图像
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
}Anchors;

// 精灵图的渲染模式
typedef enum RenderMode {
	RENDER_GPU,		// GPU渲染模式
	RENDER_CPU		// CPU渲染模式
}RenderMode;

// 图像信息
struct ImageInfo {
	std::string path;
	int x, y;
};

class Sprite : public Asset{
public:
	Sprite(std::vector<ImageInfo>paths, Uint w, Uint h);
	~Sprite();

public:	
	void Update(int x, int y);								  // 更新逻辑
	std::vector<std::string> GetPath() const;	  			  // 获取全部图像路径
	std::string GetPath(int n) const;
	int  ChangePath(std::string &path, Uint w, Uint h);		  // 修改图像路径
	int  SetZoom(float z);									  // 设置图像缩放比
	
private:
	Uint weight, height   = 0;
	float    zoom         = 1.0f;	 // 图像缩放 
	Anchors  anchors      = MIDDLE;	 
	RenderMode rendermode = RENDER_GPU;
	std::vector<ImageInfo> images;

	SDL_Rect     renderRect;			   // 渲染矩形
	SDL_Surface* spriteSurface = nullptr;  // 图像表面（CPU渲染模式）
	SDL_Texture* spriteTexture = nullptr;  // 图像贴图（GPU渲染模式）

public:
	//获取Sprite类锚点
	inline Anchors GetAnchors() {
		return this->anchors;
	}

	// 获取图像缩放比
	inline float GetZoom() {
		return this->zoom;
	}
};

#endif