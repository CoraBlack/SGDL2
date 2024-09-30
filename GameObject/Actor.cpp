
#include "Actor.h"

/*
 * Actor::Actor 构造函数
 * 参数： string path 图像路径
 *		  Uint w	  图像宽度
 *		  Uint h	  图像高度
 * 返回值 void
 * 功能： 使用Sprite对象初始化Actor
 */
Actor::Actor(std::string& path, Uint w, Uint h) {
	this->sprite = new Sprite(path, w, h);// 初始化Sprite对象
}



/*
 * Actor::Actor 构造函数
 * 参数： Sprite s
 * 返回值 void
 * 功能： 使用Sprite对象初始化Actor
 */
Actor::Actor(Sprite s) {
	this->sprite = &s; // 初始化Sprite对象
}
