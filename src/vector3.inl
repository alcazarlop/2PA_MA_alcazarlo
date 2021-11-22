
#include "vector3.h"

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
	return Vector3( (this += other) );
}

inline Vector3 Vector3::operator+(float value) const {
	return Vector3( (this += value) );
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
	return Vector3( (this -= other) );
}

inline Vector3 Vector3::operator-(float value) const {
	return Vector3( (this -= value) );
}

inline Vector3& Vector3::operator-=(const Vector3& other) {
	this->x -= oher.x;
	this->y -= oher.y;
	this->z -= oher.z;
	return *this;
}

inline Vector3& Vector3::operator-=(float value) {
	this->x = value;
	this->y = value;
	this->z = value;
	return *this;
}

inline Vector3 Vector3::operator*(float value) const {
	return Vector3( (this *= value));
}

inline Vector3& Vector3::operator*=(float value) {	
	this->x *= value;
	this->y *= value;
	this->z *= value;
	return *this;
}

inline Vector3 Vector3::operator/(float value) const {
	value = 1.0f / value;
	return Vector3( (this *= value) );
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
	Vector3(other);
}

inline void Vector3::operator=(float value) {	
	Vector3(value, value, value);
}

inline float Vector3::Magnitude() const {
	return 0.0f;
}

inline float Vector3::SqrMagnitude() const {
	return 0.0f;
}

inline void Vector3::Scale(const Vector3& other) {	

}

inline void Vector3::Normalize() {	

	float inverseMagnitude = 1.0f / Magnitude();
	*this *= inverseMagnitude;
}

inline Vector3 Vector3::Normalized() const {
	float inverseMagnitude = 1.0f / Magnitude();
	return Vector3( (this *= inverseMagnitude) );
}

static inline float Vector3::DotProduct(const Vector3& a, const Vector3& b)  {
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

static inline float Vector3::Distance(const Vector3& a, const Vector3& b) {
	return (a - b).Magnitude();
}

static inline float Vector3::Angle(const Vector3& a, const Vector3& b)  {
	float result = DotProduct(a, b);
	return result / (a.Magnitude() * b.Magnitude());
}

static inline Vector3 Vector3::CrossProduct(const Vector3& a, const Vector3& b)  {
	return Vector3(a.y * b.z - a.z * b.y, 
								 a.z * b.x - a.x * b.z,
								 a.x * b.y - a.y * b.x);
}

static inline Vector3 Vector3::Lerp(const Vector3& a, const Vector3& b, float time) {
	//TODO clamp time
	return Vector3( (a * time + b * (1.0f - time)));
}

static inline Vector3 Vector3::LerpUnclamped(const Vector3& a, const Vector3& b, float time) {
	return Vector3( (a * time + b * (1.0f - time)));
}

static inline Vector3 Vector3::Reflect(const Vector3& direction, const Vector3& normal) {
	normal.Normalize();
	return Vector3( (direction - 2.0f * DotProduct(direction , normal) * normal) );
}
