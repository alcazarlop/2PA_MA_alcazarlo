
#include "vector4.h"

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
	this->x = w;
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
	return Vector4( (this += other) );
}

inline Vector4 Vector4::operator+(float value) const{
	return Vector4( (this += value) );
}

inline void Vector4::operator+=(const Vector4& other) {
	*this->x += other.x;
	*this->y += other.y;
	*this->z += other.z;
	*this->w += other.w;
}

inline void Vector4::operator+=(float value) {
	*this->x += value;
	*this->y += value;
	*this->z += value;
	*this->w += value;
}

inline Vector4 Vector4::operator-(const Vector4& other) const{
	return Vector4( (this -= other) );
}

inline Vector4 Vector4::operator-(float value) const{
	return Vector4( (this -= value) );
}

inline void Vector4::operator -=(const Vector4& other) {	
	*this->x -= other.x;
	*this->y -= other.y;
	*this->z -= other.z;
	*this->w -= other.w;
}

inline void Vector4::operator -=(float value) {
	*this->x -= other.x;
	*this->y -= other.y;
	*this->z -= other.z;
	*this->w -= other.w;
}

inline Vector4 Vector4::operator*(float value) const{
	return Vector4( (this *= value) );
}

inline void Vector4::operator*=(float value) {
	this->x *= value;
	this->y *= value;
	this->z *= value;
	this->w *= value;
}

inline Vector4 Vector4::operator/(float value) const{
	value = 1.0f / value;
	return Vector4( (this *= value) );
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
	Vector4(other);
}

inline float Vector4::Magnitude() const{
	return sqrtf(Magnitude());
}

inline void Vector4::Normalize() {
	float inverse = 1.0f / Magnitude();
	*this *= inverse;
}

inline Vector4 Vector4::Normalized() const {
	float inverse = 1.0f / Magnitude();
	return Vector4( (this *= inverse) );
}

inline void Vector4::Scale(Vector4 scale) {	
	Vector4(this->x * scale.x, this->y * scale.y, 
					this->z * scale.z, this->w * scale.w);

}

inline float Vector4::SqrMagnitude() const {
	return (x * x + y * y + z * z + w * w);
}

static inline float Vector4::Distance(const Vector4& a, const Vector4& b) {
	return (a - b).Magnitude();
}

static inline float Vector4::DotProduct(Vector4 a, Vector4 b) {
	a.Normalize();
	b.Normalize();
	return (a.x + b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

static inline Vector4 Vector4::Lerp(const Vector4& a, const Vector4& b, float time) {	
	return Vector4( (a * time + b * (1.0f - time)));
}
