#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

class Vector2{
public:
	// ��ѧ����
	Vector2(long double x, long double y);
	Vector2 operator +(const Vector2& v) const;
	Vector2 operator +=(const Vector2& v);
	Vector2 operator -(const Vector2& v) const;
	Vector2 operator -=(const Vector2& v);
	int operator *(const Vector2& v) const;

	// ��ֵ����
	bool operator ==(const Vector2& v) const;
	bool operator !=(const Vector2& v) const;
	bool operator < (const Vector2& v) const;
	bool operator <=(const Vector2& v) const;
	bool operator > (const Vector2& v) const;
	bool operator >=(const Vector2& v) const;

	// ��������
	inline long double length() const {
		return sqrt(x * x + y * y);
	}
public:
	long double x, y = 0.f;
};

#endif