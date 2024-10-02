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
	LEFT_TOP  ,		// ����
	MIDDLE_TOP,		// ����
	RIGHT_TOP ,		// ����
	LEFT_MIDDLE ,	// ����
	MIDDLE	    ,	// ����
	RIGHT_MIDDLE,	// ����
	LEFT_BOTTOM  ,	// ����
	MIDDLE_BOTTOM,	// ����
	RIGHT_BOTTOM ,	// ����
}Anchors;	//ê������

class Sprite : protected Asset{
public:
	Sprite(std::string &path, Uint w, Uint h);
	~Sprite();

public:
	std::string GetPath() const;							  // ��ȡͼ��·��
	int ChangePath(std::string &path, Uint w, Uint h);		  //�޸�ͼ��·��
	int SetZoom(float z);									  // ����ͼ�����ű�

public:
	Uint weight, height = 0; // ͼ��Ŀ��

private:
	float zoom = 1.0f;		 // ͼ������ 
	Anchors anchors = MIDDLE;// ͼ��ê��
};

#endif