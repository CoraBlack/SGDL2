#include "Window.h"

Window::Window(std::string title,
	unsigned int locate_x,
	unsigned int locate_y,
	unsigned int size_x,
	unsigned int size_y, 
	Uint32 flags
) {

	// ³õÊ¼»¯´°¿Ú
	this->win = SDL_CreateWindow(title.c_str(), locate_x, locate_y, size_x, size_y, flags);
	

}