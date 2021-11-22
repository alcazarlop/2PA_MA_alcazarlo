
#include "vector2.h"

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
  return Vector2( (this += other) );
}

inline Vector2 Vector2::operator+(float value) {
  return Vector2( (this += value) );
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
  return Vector2( (this += other) );
}

inline Vector2 Vector2::operator-(float value) const {
  return Vector2( (this -= value) );
}

inline Vector2& Vector2::operator-() {
	return Vector2(this->-x, this->-y);
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
	Vector2(other);
}

inline void Vector2::operator=(float value) {
	Vector2(value, value);
}

inline Vector2 Vector2::operator*(float value) const {
	return Vector2( (this *= value) );
}

inline Vector2& Vector2::operator*=(float value) {  
	this->x *= value;
	this->y *= value;
  return *this;
}

inline Vector2 Vector2::operator/(float value) const {
	value = 1.0f / value;
	return Vector2( (this *= value) );
}

inline Vector2& Vector2::operator/=(float value) {
	value = 1.0f / value;
	this->x *= value;
	this->y *= value;
	return Vector2();
}

inline float Vector2::Magnitude() const {
  return sqrtf(SqrMagnitude());
}

inline float Vector2::SqrMagnitude() const {
  return (x * x + y * y);
}

inline void Vector2::Scale(const Vector2 scale){
	Vector2( this->x * scale.x, this->y * scale.y );
}

inline void Vector2::Normalize() { 
	float inverse = 1.0f / Magnitude();
	*this *= inverse; 
}

inline Vector2 Vector2::Normalized() const {
	float inverse = 1.0f / Magnitude();
	return Vector2( (this *= inverse) );
}

static inline float Vector2::Distance(const Vector2 a, const Vector2 b) {
  return (a - b).Magnitude();
}

static inline float Vector2::DotProduct(Vector2 a, Vector2 b) {
	a.Normalize();
	b.Normalize();
	return (a.x * b.x + a.y * b.y);
}

static inline Vector2 Vector2::Lerp(const Vector2 a, const Vector2 b, float time) {
	//TODO -> Time entre 0  y 1 (Clamp)
	return Vector2( (a * time + b * (1.0f - time)) );
}

static inline Vector2 Vector2::LerpUnclamped(const Vector2 a, const Vector2 b, float time) {
	return Vector2( (a * time + b * (1.0f - time)) );
}
