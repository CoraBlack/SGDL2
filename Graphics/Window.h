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
	Window(std::string title,	// ���ڱ���
			int x,				// ��������x
			int y,				// ��������y
			unsigned int w,		// ���ڿ��
			unsigned int h,		// ���ڿ��
			Uint32 flags		// ����ģʽ
	);
	~Window() = default;

private:
	SDL_Window* win = nullptr;
	Scene* scene = nullptr;
};

#endif 