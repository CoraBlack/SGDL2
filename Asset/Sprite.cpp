#include <fstream>
#include <iostream>
#include "Sprite.h"

/*
 *	��Sprite���캯��
 *  ������string path:    �ļ�·��
 *		  unsigned int w: ͼ����
 *		  unsigned int h: ͼ��߶�
 *  ����ֵ void
 *  ���ܣ���ȡ�ļ��Ҽ���Ƿ����
 *		  �����ļ����ͣ�����ʼ����Ӧ��SDL_imageģ��
 */
Sprite::Sprite(std::string &path, Uint w, Uint h) : Asset(path){
	
	// ����ļ��Ƿ����
	{
		std::ifstream file(path);
		if (!file.is_open()) {
			std::cout << "Error: File " << path << " not found." << std::endl;
			return;
		}
		file.close();
		this->path = path; // д���Ա����
	}

	// ����ļ�����
	{
		std::string file_type = "";

		for (int i = path.size() - 1; i >= 0; --i) { // ���ַ�����ĩβ��ʼ����
			if (path[i] == '.') { // ���ҵ�'.'����Ӹ�λ�ÿ�ʼ�����ȡ
				for (auto j = i + 1; j <= path.size(); ++j) {
					file_type += path[j];
				}
				break;
			}
		}
		
		// ��ʼ��SDL2�ж�Ӧ���ļ�����ģ��
		do {
			// Initialize PNG module
			if (file_type == "png") {
				if (SDL_WasInit(IMG_INIT_PNG)) {
					IMG_Init(IMG_INIT_JPG);
				}
				break;
			}

			// Initialize JPG module
			if (file_type == "jpg") {
				if (SDL_WasInit(IMG_INIT_JPG)) {
					IMG_Init(IMG_INIT_PNG);
				}
				break;
			}

			// Initialize JXL module
			if (file_type == "jxl") {
				if (SDL_WasInit(IMG_INIT_JXL)) {
					IMG_Init(IMG_INIT_JXL);
				}
				break;
			}

			// Initialize AVIF module
			if (file_type == "avif") {
				if (SDL_WasInit(IMG_INIT_AVIF)) {
					IMG_Init(IMG_INIT_AVIF);
				}
				break;
			}

		}while (0);
	}
	return;
}

Sprite::~Sprite() {
	
}

std::string Sprite::GetPath() const {
	return this->path;
}



/*
 * Sprite::ChangePath
 * ������ string path��   ��ͼ���ļ�·��
 *        unsigned int w����ͼ����
 *        unsigned int h����ͼ��߶�
 * ����ֵ��int
 *		   0���ɹ�����Ķ�ȡ���޸�·��
 *         -1���޷���ȡ�ļ�
 * ���ܣ��ı�Sprite�����ͼ��·���������³�ʼ��ͼ�����
 */
int Sprite::ChangePath(std::string &path, Uint w, Uint h) {
	/*����ļ��Ƿ����*/
	{
		std::ifstream filePath(path);
		if (!filePath.good()) {
			//�ļ���ʧ�ܣ����� -1
			return -1;
		}
	}

	this->path = path;
	this->weight, height = w, h;

	/*

	// ���rect�Ƿ�Ϊ����ָ��
	if (this->rect != nullptr) {
		this->rect->w, h = (int)w, (int)h;
	}
	else {
		this->rect = new SDL_Rect{ 0,0,(int)w,(int)h };
	}

	*/

	return 0;
	
}


/*
 * Sprite::SetZoom
 * ������float z: ͼ������ű���(����Ϊ��������)
 * ����ֵ��int
 *		   0���ɹ������µ�zoom���ű���
 *		   -1�����õ����ű���С�ڵ���0��ʧ��
 */
int Sprite::SetZoom(float z) {
	if (z <= 0) {
		return -1;
	}

	this->zoom = z;
	return 0;
}