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
Sprite::Sprite(std::vector<ImageInfo>paths, Uint w, Uint h){
	
	// ����ļ��Ƿ����
	for (auto i = 0; i < paths.size(); ++i) {
		std::ifstream file(paths[i].path);
		// �޷����ļ�
		if (!file.is_open()) {
			std::cerr << "Error: File " << paths[i].path << " not found or falied to open." << std::endl;
			paths.erase(paths.begin() + i);	// �Ƴ������õ�ͼ����Ϣ
			file.close();
			continue;
		}

		file.close();
		this->images.push_back(paths[i]); // д���Ա����
	}

	
	std::string file_type = "";
	for (auto p : paths){

		// ����ļ�����
		for (int i = p.path.size() - 1; i >= 0; --i) { // ���ַ�����ĩβ��ʼ����
			if (p.path[i] == '.') {		  // ���ҵ�'.'����Ӹ�λ�ÿ�ʼ�����ȡ
				for (auto j = i + 1; j <= p.path.size(); ++j) {
					file_type += p.path[j];
				}
				break;
			}
		}
		
		// ��ʼ��SDL2�ж�Ӧ���ļ�����ģ��
			// Initialize PNG module
			if (file_type == "png") {
				if (SDL_WasInit(IMG_INIT_PNG)) {
					IMG_Init(IMG_INIT_JPG);
				}
			}

			// Initialize JPG module
			if (file_type == "jpg") {
				if (SDL_WasInit(IMG_INIT_JPG)) {
					IMG_Init(IMG_INIT_PNG);
				}
			}

			// Initialize JXL module
			if (file_type == "jxl") {
				if (SDL_WasInit(IMG_INIT_JXL)) {
					IMG_Init(IMG_INIT_JXL);
				}
			}

			// Initialize AVIF module
			if (file_type == "avif") {
				if (SDL_WasInit(IMG_INIT_AVIF)) {
					IMG_Init(IMG_INIT_AVIF);
				}
			}
	}

	// �����ļ�������
	if (paths.empty()) {
		std::cerr << "All of image could't load!" << std::endl;
	}

	return;
}

Sprite::~Sprite() {
	
}

ImageInfo Sprite::GetPath() const {
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

	this->images = path;
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


void Sprite::Update(int x, int y) {
	
}
