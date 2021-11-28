
#ifndef __VECTOR4_H__
#define __VECTOR4_H__ 1

#include <math.h>
#include "vector3.h"
#include "math_utils.h"

class Vector4 {

 public:

 	Vector4();
 	Vector4(float x, float y, float z, float w);
 	Vector4(Vector3 other, float w);
 	Vector4(float value);
 	Vector4(float* values_array);
 	Vector4(const Vector4& other);
 	~Vector4();

 	Vector4 operator+(const Vector4& other) const;
 	Vector4 operator+(float value) const;
 	void operator+=(const Vector4& other);
 	void operator+=(float value);
 	Vector4 operator-(const Vector4& other) const;
 	Vector4 operator-(float value) const;
 	void operator-=(const Vector4& other);
 	void operator-=(float value);
 	Vector4 operator*(float value) const;
 	void operator*=(float value);
 	Vector4 operator/(float value) const;
 	void operator/=(float value);

 	bool operator==(const Vector4& other);
 	bool operator!=(const Vector4& other);
 	void operator=(const Vector4& other);

 	float Magnitude() const;
 	void Normalize();
 	Vector4 Normalized() const;

 	void Scale(Vector4 scale);
 	float SqrMagnitude() const;

 	static float Distance(const Vector4& a, const Vector4& b);
 	static float DotProduct(Vector4 a, Vector4 b);
 	static Vector4 Lerp(const Vector4& a, const Vector4& b, float time);

 	static const Vector4 one;
 	static const Vector4 zero;

 	float x;
 	float y;
 	float z;
 	float w;

};

inline Vector4::Vector4() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
}

inline Vector4::Vector4(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline Vector4::Vector4(Vector3 other, float w) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = w;
}

inline Vector4::Vector4(float value) {
	this->x = value;
	this->y = value;
	this->z = value;
	this->w = value;
}

inline Vector4::Vector4(float* values_array) {
	this->x = values_array[0];
	this->y = values_array[1];
	this->z = values_array[2];
	this->w = values_array[3];
}

inline Vector4::Vector4(const Vector4& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
}

inline Vector4::~Vector4() { }

inline Vector4 Vector4::operator+(const Vector4& other) const{
	Vector4 result(*this);
	result += other;
	return result;
}

inline Vector4 Vector4::operator+(float value) const{
	Vector4 result(*this);
	result += value;
	return result;
}

inline void Vector4::operator+=(const Vector4& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
}

inline void Vector4::operator+=(float value) {
	this->x += value;
	this->y += value;
	this->z += value;
	this->w += value;
}

inline Vector4 Vector4::operator-(const Vector4& other) const{
	Vector4 result(*this);
	result -= other;
	return result;

}

inline Vector4 Vector4::operator-(float value) const{
	Vector4 result(*this);
	result -= value;
	return result;
}

inline void Vector4::operator -=(const Vector4& other) {	
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
}

inline void Vector4::operator -=(float value) {
	this->x -= value;
	this->y -= value;
	this->z -= value;
	this->w -= value;
}

inline Vector4 Vector4::operator*(float value) const{
	Vector4 result(*this);
	result *= value;
	return result;
}

inline void Vector4::operator*=(float value) {
	this->x *= value;
	this->y *= value;
	this->z *= value;
	this->w *= value;
}

inline Vector4 Vector4::operator/(float value) const{
	value = 1.0f / value;
	Vector4 result(*this);
	result *= value;
	return result;
}

inline void Vector4::operator/=(float value) {
	value = 1.0f / value;
	*this *= value;
}

inline bool Vector4::operator==(const Vector4& other) {
	return (this->x == other.x && this->y == other.y &&
					this->z == other.z && this->w == other.w);
}
inline bool Vector4::operator!=(const Vector4& other) {
	return (this->x == other.x && this->y == other.y &&
					this->z == other.z && this->w == other.w);
}
inline void Vector4::operator=(const Vector4& other) {
	Vector4(this->x = other.x, this->y = other.y, this->z = other.z, this->w = other.w);
}

inline float Vector4::Magnitude() const{
	return sqrtf(SqrMagnitude());
}

inline void Vector4::Normalize() {
	float inverse = 1.0f / Magnitude();
	*this *= inverse;
}

inline Vector4 Vector4::Normalized() const {
	float inverse = 1.0f / Magnitude();
	Vector4 result(*this);
	result *= inverse;
	return result;
}

inline void Vector4::Scale(Vector4 scale) {	
	Vector4(this->x * scale.x, this->y * scale.y, 
					this->z * scale.z, this->w * scale.w);

}

inline float Vector4::SqrMagnitude() const {
	return (x * x + y * y + z * z + w * w);
}

inline float Vector4::Distance(const Vector4& a, const Vector4& b) {
	return (a - b).Magnitude();
}

inline float Vector4::DotProduct(Vector4 a, Vector4 b) {
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

inline Vector4 Vector4::Lerp(const Vector4& a, const Vector4& b, float time) {	
	time = MathUtils::Clamp(time, 0.0f, 1.0f);
	return Vector4((a.x + time) * (b.x - a.x), (a.y + time) * (b.y - a.y),
								 (a.z + time) * (b.z - a.z), (a.w + time) * (b.w - a.w));
}

#endif //__VECTOR4_H__