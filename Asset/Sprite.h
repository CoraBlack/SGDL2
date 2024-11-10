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

// ê�����ͣ�ͨ����ͬ��ê��ȥ��ʾͼ��
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
}Anchors;

// ����ͼ����Ⱦģʽ
typedef enum RenderMode {
	RENDER_GPU,		// GPU��Ⱦģʽ
	RENDER_CPU		// CPU��Ⱦģʽ
}RenderMode;

// ͼ����Ϣ
struct ImageInfo {
	std::string path;
	int x, y;
};

class Sprite : public Asset{
public:
	Sprite(std::vector<ImageInfo>paths, Uint w, Uint h);
	~Sprite();

public:	
	void Update(int x, int y);								  // �����߼�
	std::vector<std::string> GetPath() const;	  			  // ��ȡȫ��ͼ��·��
	std::string GetPath(int n) const;
	int  ChangePath(std::string &path, Uint w, Uint h);		  // �޸�ͼ��·��
	int  SetZoom(float z);									  // ����ͼ�����ű�
	
private:
	Uint weight, height   = 0;
	float    zoom         = 1.0f;	 // ͼ������ 
	Anchors  anchors      = MIDDLE;	 
	RenderMode rendermode = RENDER_GPU;
	std::vector<ImageInfo> images;

	SDL_Rect     renderRect;			   // ��Ⱦ����
	SDL_Surface* spriteSurface = nullptr;  // ͼ����棨CPU��Ⱦģʽ��
	SDL_Texture* spriteTexture = nullptr;  // ͼ����ͼ��GPU��Ⱦģʽ��

public:
	//��ȡSprite��ê��
	inline Anchors GetAnchors() {
		return this->anchors;
	}

	// ��ȡͼ�����ű�
	inline float GetZoom() {
		return this->zoom;
	}
};

#endif