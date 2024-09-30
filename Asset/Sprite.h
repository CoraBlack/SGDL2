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
	int LoadInfoToMemory(SDL_Renderer* target/*Ŀ����ɫ��*/); // ����ͼ����ͼ����������ڴ�
	int DestroyInfoFromMemory(); // �ͷ�ͼ���ڴ�
	std::string GetPath() const; // ��ȡͼ��·��
	int ChangePath(std::string &path, Uint w, Uint h);		 //�޸�ͼ��·��
	void SetZoom(float z);       // ����ͼ�����ű�

public:
	Uint weight, height = 0; // ͼ��Ŀ��

private:
	std::string path = "";	//�ļ�·��
	float zoom = 1.0f;		// ͼ������ű���
	SDL_Rect* rect = nullptr; 
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
};

#endif