
#include "Actor.h"

/*
 * Actor::Actor ���캯��
 * ������ string path ͼ��·��
 *		  Uint w	  ͼ����
 *		  Uint h	  ͼ��߶�
 * ����ֵ void
 * ���ܣ� ʹ��Sprite�����ʼ��Actor
 */
Actor::Actor(std::string& path, Uint w, Uint h) {
	this->sprite = new Sprite(path, w, h);// ��ʼ��Sprite����
}



/*
 * Actor::Actor ���캯��
 * ������ Sprite s
 * ����ֵ void
 * ���ܣ� ʹ��Sprite�����ʼ��Actor
 */
Actor::Actor(Sprite s) {
	this->sprite = &s; // ��ʼ��Sprite����
}
