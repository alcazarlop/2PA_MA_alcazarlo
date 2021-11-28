
#ifndef __VECTOR2_H__
#define __VECTOR2_H__ 1

#include <math.h>
#include "math_utils.h"

class Vector2 {

 public:
	
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& copy);	
	~Vector2();

	Vector2 operator+(const Vector2& other) const; 	
	Vector2 operator+(float value); 	
	Vector2& operator+=(const Vector2& other);
	Vector2& operator+=(float value);
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-(float value) const;
	Vector2& operator-();
	Vector2& operator-=(const Vector2& other);
	Vector2& operator-=(float value);
	Vector2 operator*(float value) const;
	Vector2& operator*=(float value);
	Vector2 operator/(float value) const;
	Vector2& operator/=(float value);

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;
	void operator=(const Vector2& other);
	void operator=(float value);

	float Magnitude() const;
	float SqrMagnitude() const;

	void Scale(const Vector2 scale);
	void Normalize();
	Vector2 Normalized() const;

	static float Distance(const Vector2 a, const Vector2 b);
	static float DotProduct(const Vector2 a, const Vector2 b);

	static Vector2 Lerp(const Vector2, const Vector2, float time);
	static Vector2 LerpUnclamped(const Vector2, const Vector2, float time);

  static const Vector2 up;
  static const Vector2 down;
  static const Vector2 right;
  static const Vector2 left;
  static const Vector2 zero;
  static const Vector2 one;

	float x;
	float y;

};

inline Vector2::Vector2() {
	this->x = 0.0f;
	this->y = 0.0f;
}

inline Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}

inline Vector2::Vector2(const Vector2& other) {
	this->x = other.x;
	this->y = other.y;
}

inline Vector2::~Vector2() {}

inline Vector2 Vector2::operator+(const Vector2& other) const {
	Vector2 result(*this);
	result += other;
  return result;
}

inline Vector2 Vector2::operator+(float value) {
	Vector2 result(*this);
	result += value;
  return result;
}

inline Vector2& Vector2::operator+=(const Vector2& other){
	this->x = other.x;
	this->y = other.y;
  return *this;
}

inline Vector2& Vector2::operator+=(float value){
	this->x = value;
	this->y = value;
  return *this;
}

inline Vector2 Vector2::operator-(const Vector2& other) const {
	return (Vector2(this->x - other.x, this->y - other.y));
}

inline Vector2 Vector2::operator-(float value) const {
	return (Vector2(this->x - value, this->y - value));
}

inline Vector2& Vector2::operator-() {
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& other) {
	this->x -= other.x;
	this->y -= other.y;
  return *this;
}

inline Vector2& Vector2::operator-=(float value){
	this->x -= value;
	this->y -= value;
  return *this;
}

inline bool Vector2::operator==(const Vector2& value) const {
  return (this->x == value.x && this->y == value.y);
}

inline bool Vector2::operator!=(const Vector2& value) const {
  return (this->x != value.x || this->y != value.y);
}


inline void Vector2::operator=(const Vector2& other) {
	Vector2(this->x = other.x, this->y = other.y);
}

inline void Vector2::operator=(float value) {
	Vector2(value, value);
}

inline Vector2 Vector2::operator*(float value) const {
	Vector2 result(*this);
	result *= value;
	return result;
}

inline Vector2& Vector2::operator*=(float value) {  
	this->x *= value;
	this->y *= value;
  return *this;
}

inline Vector2 Vector2::operator/(float value) const {
	value = 1.0f / value;
	Vector2 result(*this);
	result *= value;
	return result;
}

inline Vector2& Vector2::operator/=(float value) {
	value = 1.0f / value;
	this->x *= value;
	this->y *= value;
	return *this;
}

inline float Vector2::Magnitude() const {
  return sqrtf(SqrMagnitude());
}

inline float Vector2::SqrMagnitude() const {
  return (x * x + y * y);
}

inline void Vector2::Scale(const Vector2 scale){
	// this->x * scale.x;
	// this->y * scale.y;
}

inline void Vector2::Normalize() { 
	float inverse = 1.0f / Magnitude();
	*this *= inverse; 
}

inline Vector2 Vector2::Normalized() const {
	float inverse = 1.0f / Magnitude();
	Vector2 result(*this);
	result *= inverse;
	return result;
}

inline float Vector2::Distance(const Vector2 a, const Vector2 b) {
  return (a - b).Magnitude();
}

inline float Vector2::DotProduct(Vector2 a, Vector2 b) {
	return (a.x * b.x + a.y * b.y);
}

inline Vector2 Vector2::Lerp(const Vector2 a, const Vector2 b, float time) {
	time = MathUtils::Clamp(time, 0.0f, 1.0f);
	return Vector2(LerpUnclamped(a, b, time));
}

inline Vector2 Vector2::LerpUnclamped(const Vector2 a, const Vector2 b, float time) {
	return Vector2((a.x + time) * (b.x - a.x), (a.y + time) * (b.y - a.y));
}

#endif // __VECTOR2_H__
