#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

class Vector2{
public:
	// 数学运算
	Vector2(long double x, long double y);
	Vector2 operator +(const Vector2& v) const;
	Vector2 operator +=(const Vector2& v);
	Vector2 operator -(const Vector2& v) const;
	Vector2 operator -=(const Vector2& v);
	int operator *(const Vector2& v) const;

	// 较值运算
	bool operator ==(const Vector2& v) const;
	bool operator !=(const Vector2& v) const;
	bool operator < (const Vector2& v) const;
	bool operator <=(const Vector2& v) const;
	bool operator > (const Vector2& v) const;
	bool operator >=(const Vector2& v) const;

	// 操作函数
	inline long double length() const {
		return sqrt(x * x + y * y);
	}
public:
	long double x, y = 0.f;
};

#endif