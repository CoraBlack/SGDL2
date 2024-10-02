#include <fstream>
#include <iostream>
#include "Sprite.h"

/*
 *	类Sprite构造函数
 *  参数：string path:    文件路径
 *		  unsigned int w: 图像宽度
 *		  unsigned int h: 图像高度
 *  返回值 void
 *  功能：读取文件且检查是否可用
 *		  解析文件类型，并初始化相应的SDL_image模块
 */
Sprite::Sprite(std::string &path, Uint w, Uint h) : Asset(path){
	
	// 检查文件是否存在
	{
		std::ifstream file(path);
		if (!file.is_open()) {
			std::cout << "Error: File " << path << " not found." << std::endl;
			return;
		}
		file.close();
		this->path = path; // 写入成员变量
	}

	// 检查文件类型
	{
		std::string file_type = "";

		for (int i = path.size() - 1; i >= 0; --i) { // 从字符串的末尾开始查找
			if (path[i] == '.') { // 若找到'.'，则从该位置开始往后截取
				for (auto j = i + 1; j <= path.size(); ++j) {
					file_type += path[j];
				}
				break;
			}
		}
		
		// 初始化SDL2中对应的文件类型模块
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
 * 参数： string path：   新图像文件路径
 *        unsigned int w：新图像宽度
 *        unsigned int h：新图像高度
 * 返回值：int
 *		   0：成功无误的读取并修改路径
 *         -1：无法读取文件
 * 功能：改变Sprite对象的图像路径，并重新初始化图像矩形
 */
int Sprite::ChangePath(std::string &path, Uint w, Uint h) {
	/*检查文件是否可用*/
	{
		std::ifstream filePath(path);
		if (!filePath.good()) {
			//文件打开失败，返回 -1
			return -1;
		}
	}

	this->path = path;
	this->weight, height = w, h;

	/*

	// 检查rect是否为可用指针
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
 * 参数：float z: 图像的缩放比例(必须为正浮点数)
 * 返回值：int
 *		   0：成功设置新的zoom缩放比例
 *		   -1：设置的缩放比例小于等于0，失败
 */
int Sprite::SetZoom(float z) {
	if (z <= 0) {
		return -1;
	}

	this->zoom = z;
	return 0;
}