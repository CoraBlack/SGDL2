#include "Window.h"

/*
 * ��Window���캯��
 * ������string title 		���ڱ���
 *		 int x 				��������x
 *		 int y				��������y
 *		 unsigned int w 	���ڿ��
 *		 unsigned int h 	���ڿ��
 *		 Uint32 flags		����ģʽ
 * ����ֵ��void
 * ���ã�������ϷӦ�û�������Window
 *		 ��������ʼ��һ������
 */

Window::Window(std::string title,
	int x,
	int y,
	unsigned int w,
	unsigned int h, 
	Uint32 flags
) {

	// ��ʼ������
	this->win = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
	

}