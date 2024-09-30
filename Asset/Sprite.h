#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>

#define Uint unsigned int

class Sprite{
public:
	Sprite(std::string &path, Uint w, Uint h);
	~Sprite();

public:
	int LoadInfoToMemory(SDL_Renderer* target/*目标着色器*/); // 加载图像到贴图对象和载入内存
	int DestroyInfoFromMemory(); // 释放图像内存
	std::string GetPath() const; // 获取图像路径
	int ChangePath(std::string &path, Uint w, Uint h);		 //修改图像路径
	void SetZoom(float z);       // 设置图像缩放比

public:
	Uint weight, height = 0; // 图像的宽高

private:
	std::string path = "";	//文件路径
	float zoom = 1.0f;		// 图像的缩放比例
	SDL_Rect* rect = nullptr; 
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
};

#endif