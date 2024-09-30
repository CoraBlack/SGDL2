#include <math.h>
#include "Vector2.h"

Vector2::Vector2(long double x, long double y) {
	this->x = x;
	this->y = y;
	return;
}

Vector2 Vector2::operator +(const Vector2& v) const {
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator += (const Vector2& v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vector2 Vector2::operator - (const Vector2& v) const {
	return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator -= (const Vector2& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

int Vector2::operator * (const Vector2& v) const {
	return (this->x * v.x + this->y * v.y);
}



bool Vector2::operator==(const Vector2& v) const {
	if (this->x == v.x && this->y == v.y) {
		return true;
	} else {
		return false;
	}
}

bool Vector2::operator!=(const Vector2& v) const{
	if (this->x != v.x && this->y != v.y) {
		return true;
	} else {
		return false;
	}
}

bool Vector2::operator< (const Vector2& v) const{
	if (sqrt(x * x + y * y) < sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	} else {
		return false;
	}
}

bool Vector2::operator<=(const Vector2& v) const{
	if (sqrt(x * x + y * y) <= sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector2::operator> (const Vector2& v) const{
	if (sqrt(x * x + y * y) > sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	}
	else {
		return false;
	}
}

bool Vector2::operator>=(const Vector2& v) const{
	if (sqrt(x * x + y * y) >= sqrt(v.x * v.x + v.y * v.y)) {
		return true;
	}
	else {
		return false;
	}
}

