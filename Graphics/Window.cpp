#include "Window.h"

/*
 * 类Window构造函数
 * 参数：string title 		窗口标题
 *		 int x 				窗口坐标x
 *		 int y				窗口坐标y
 *		 unsigned int w 	窗口宽度
 *		 unsigned int h 	窗口宽度
 *		 Uint32 flags		窗口模式
 * 返回值：void
 * 作用：构建游戏应用基本容器Window
 *		 创建并初始化一个窗口
 */

Window::Window(std::string title,
	int x,
	int y,
	unsigned int w,
	unsigned int h, 
	Uint32 flags
) {

	// 初始化窗口
	this->win = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
	

}