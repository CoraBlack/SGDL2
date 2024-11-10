#ifndef WINDOW_H
#define WINDOW_H

#include "Platform.h"

#ifdef WIN32
#include <SDL.h>
#endif // WIN32

#ifdef LINUX
#include <SDL2/SDL.h>
#endif

#include <string>
#include "Scene.h"

class Window {
public:
	Window(std::string title,	// 窗口标题
			int x,				// 窗口坐标x
			int y,				// 窗口坐标y
			unsigned int w,		// 窗口宽度
			unsigned int h,		// 窗口宽度
			Uint32 flags		// 窗口模式
	);
	~Window() = default;

private:
	SDL_Window* win = nullptr;
	Scene* scene = nullptr;
};

#endif 