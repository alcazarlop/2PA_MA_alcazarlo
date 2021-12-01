
#ifndef __VECTOR3_H__
#define __VECTOR3_H__ 1

#include <math.h>
#include "math_utils.h"

class Vector3 {

 public: 

 	Vector3();
 	Vector3(float value);
 	Vector3(float x, float y, float z);
 	Vector3(float* value_array);
 	Vector3(const Vector3& other);
 	~Vector3();

 	Vector3 operator+(const Vector3& other) const;
 	Vector3 operator+(float value) const;
 	Vector3& operator+=(const Vector3& other);
 	Vector3& operator+=(float value);
 	Vector3 operator-(const Vector3& othre) const;
 	Vector3 operator-(float value) const;
 	Vector3& operator-=(const Vector3& other);
 	Vector3& operator-=(float value);
 	Vector3 operator*(float value) const;
 	Vector3& operator*=(float value);
 	Vector3 operator/(float value) const;
 	Vector3& operator/=(float value);

 	bool operator==(const Vector3& other) const;
 	bool operator!=(const Vector3& other) const;
 	void operator=(const Vector3& other);
 	void operator=(float value);

 	float Magnitude() const;
 	float SqrMagnitude() const;

 	void Scale(const Vector3& other);
 	void Normalize();
 	Vector3 Normalized() const;

 	static float DotProduct(const Vector3& a, const Vector3& b);
 	static float Distance(const Vector3& a, const Vector3& b);
 	static float Angle(const Vector3& a, const Vector3& b);

 	static Vector3 Lerp(const Vector3& a, const Vector3& b, float time);
 	static Vector3 LerpUnclamped(const Vector3& a, const Vector3& b, float time);
 	static Vector3 CrossProduct(const Vector3& a, const Vector3& b);
 	static Vector3 Reflect(const Vector3& direction, const Vector3& normal);

	static const Vector3 up;
	static const Vector3 down;
	static const Vector3 right;
	static const Vector3 left;
	static const Vector3 forward;
	static const Vector3 back;
	static const Vector3 zero;
	static const Vector3 unit;

	float x;
	float y;
	float z;

};

inline Vector3::Vector3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

inline Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

inline Vector3::Vector3(float* values_array) {
	this->x = values_array[0];
	this->y = values_array[1];
	this->z = values_array[2];
}

inline Vector3::Vector3(float value) {
	this->x = value;
	this->y = value;
	this->z = value;
}

inline Vector3::Vector3(const Vector3& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

inline Vector3::~Vector3() {}

inline Vector3 Vector3::operator+(const Vector3& other) const {
	Vector3 result(*this);
	result += other;
	return result;
}

inline Vector3 Vector3::operator+(float value) const {
	Vector3 result(*this);
	result += value;
	return result;
}

inline Vector3& Vector3::operator+=(const Vector3& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

inline Vector3& Vector3::operator+=(float value) {
	this->x += value;
	this->y += value;
	this->z += value;
	return *this;
}

inline Vector3 Vector3::operator-(const Vector3& other) const {
	Vector3 result(*this);
	result -= other;
	return result;
}

inline Vector3 Vector3::operator-(float value) const {
	Vector3 result(*this);
	result -= value;
	return result;
}

inline Vector3& Vector3::operator-=(const Vector3& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

inline Vector3& Vector3::operator-=(float value) {
	this->x -= value;
	this->y -= value;
	this->z -= value;
	return *this;
}

inline Vector3 Vector3::operator*(float value) const {
	Vector3 result(*this);
	result *= value;
	return result;
}

inline Vector3& Vector3::operator*=(float value) {	
	this->x *= value;
	this->y *= value;
	this->z *= value;
	return *this;
}

inline Vector3 Vector3::operator/(float value) const {
	value = 1.0f / value;
	Vector3 result(*this);
	result *= value;
	return result;
}

inline Vector3& Vector3::operator/=(float value) {	
	value = 1.0f / value;
	this->x *= value;
	this->y *= value;
	this->z *= value;
	return *this;
}

inline bool Vector3::operator==(const Vector3& other) const {
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}

inline bool Vector3::operator!=(const Vector3& other) const {
	return (this->x != other.x || this->y != other.y || this->z != other.z);
}

inline void Vector3::operator=(const Vector3& other) {	
	Vector3(this->x = other.x, this->y = other.y, this->z = other.z);
}

inline void Vector3::operator=(float value) {	
	Vector3(value, value, value);
}

inline float Vector3::Magnitude() const {
	return sqrtf(SqrMagnitude());
}

inline float Vector3::SqrMagnitude() const {
	return (x * x + y * y + z * z);
}

inline void Vector3::Scale(const Vector3& other) {	
	Vector3(this->x *= other.x, this->y *= other.y, this->z *= other.z);
}

inline void Vector3::Normalize() {	
	float inverseMagnitude = 1.0f / Magnitude();
	*this *= inverseMagnitude;
}

inline Vector3 Vector3::Normalized() const {
	float inverseMagnitude = 1.0f / Magnitude();
	Vector3 result(*this);
	result *= inverseMagnitude;
	return result;
}

inline float Vector3::DotProduct(const Vector3& a, const Vector3& b)  {
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline float Vector3::Distance(const Vector3& a, const Vector3& b) {
	return (a - b).Magnitude();
}

inline float Vector3::Angle(const Vector3& a, const Vector3& b)  {
	return acosf(DotProduct(a, b) / (a.Magnitude() * b.Magnitude()));
}

inline Vector3 Vector3::CrossProduct(const Vector3& a, const Vector3& b)  {
	return Vector3(a.y * b.z - a.z * b.y, 
								 a.z * b.x - a.x * b.z,
								 a.x * b.y - a.y * b.x);
}

inline Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float time) {
	time = MathUtils::Clamp(time, 0.0f, 1.0f);
	return Vector3(LerpUnclamped(a, b, time));
}

inline Vector3 Vector3::LerpUnclamped(const Vector3& a, const Vector3& b, float time) {
	return Vector3((a.x + time) * (b.x - a.x), (a.y + time) * (b.y - a.y), (a.z + time) * (b.z - a.z));
}

inline Vector3 Vector3::Reflect(const Vector3& direction, const Vector3& normal) {
	normal.Normalized();
	float dot = DotProduct(direction, normal);
	return Vector3(direction.x - 2.0f * dot * normal.x,
								 direction.y - 2.0f * dot * normal.y,
								 direction.z - 2.0f * dot * normal.z);
}

#endif // __VECTOR3_H__