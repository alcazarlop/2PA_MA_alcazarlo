#ifndef __MATRIX2_H__
#define __MATRIX2_H__ 1

#include "vector2.h"

class Matrix2x2 {
	
 public:

	Matrix2x2();
	Matrix2x2(float a[4]);
	Matrix2x2(float value);
	Matrix2x2(const Vector2& a, const Vector2& b); 
	Matrix2x2(const Matrix2x2& copy);
	~Matrix2x2();

 	Matrix2x2 operator+(const Matrix2x2& other) const;
	void operator+=(const Matrix2x2& other);
	Matrix2x2 operator+(float value) const;
	void operator+=(float value);
	Matrix2x2 operator-(const Matrix2x2& other) const;
	void operator-=(const Matrix2x2& other);
	Matrix2x2 operator-(float value) const;
	void operator-=(float value);
	Matrix2x2 operator*(float value) const;
	void operator*=(float value);
	Matrix2x2 operator/(float value) const;
	void operator/=(float value);

	bool operator==(const Matrix2x2& other) const;
	bool operator!=(const Matrix2x2& other) const;
	void operator=(const Matrix2x2& other);

	float Determinant() const;

	Vector2 GetLine(int line) const;
	Vector2 GetColum(int colum) const;

	Matrix2x2 Identity() const;
	Matrix2x2 Multiply(const Matrix2x2& other) const;
	Matrix2x2 Adjoint() const;
	Matrix2x2 Inverse() const;
	Matrix2x2 Transpose() const;

	float m[4];

};

inline Matrix2x2::Matrix2x2() {
	for(int i = 0; i < 4; ++i)
		this->m[i] = 0.0f;
}

inline Matrix2x2::Matrix2x2(float a[4]) {
	for(int i = 0; i < 4; ++i)
		this->m[i] = a[i];
}

inline Matrix2x2::Matrix2x2(float a) {
	for(int i = 0; i < 4; ++i)
		this->m[i] = a;
}

inline Matrix2x2::Matrix2x2(const Vector2& a, const Vector2& b) {
	m[0] = a.x;
	m[1] = a.y;
	m[2] = b.y;
	m[3] = b.y;
}

inline Matrix2x2::Matrix2x2(const Matrix2x2& copy) {
	for(int i = 0; i < 4; ++i)
		m[i] = copy.m[i];
}

inline Matrix2x2::~Matrix2x2() { }

inline Matrix2x2 Matrix2x2::operator+(const Matrix2x2& other) const {
	Matrix2x2 result(*this);
	for(int i = 0; i < 4; ++i)
		result->m[i] += other.m[i];
	return result;
}

inline void Matrix2x2::operator+=(const Matrix2x2& other) {
	for(int i = 0; i < 4; ++i)
		this->m[i] += other.m[i];
}

inline Matrix2x2 Matrix2x2::operator+(float value) const {
	Matrix2x2 result(*this);
	for(int i = 0; i < 4; ++i)
		result.m[i] += value;
	return result;
}

inline void Matrix2x2::operator+=(float value) {
	for(int i = 0; i < 4; ++i)
		this->m[i] += value;
}

inline Matrix2x2 Matrix2x2::operator-(const Matrix2x2& other) const {
	Matrix2x2 result(*this);
	for(int i = 0; i < 4; ++i)
		result.m[i] -= other.m[i];
	return result;
}

inline void Matrix2x2::operator-=(const Matrix2x2& other) {
	for(int i = 0; i < 4; ++i)
		this->m[i] -= other.m[i];
}

inline Matrix2x2 Matrix2x2::operator-(float value) const {	
	Matrix2x2 result(*this);
	for(int i = 0; i < 4; ++i)
		result.m[i] -= value;
	return Matrix2x2();
}

inline void Matrix2x2::operator-=(float value) {
	for(int i = 0; i < 4; ++i)
		this->m[i] -= value;
}

inline Matrix2x2 Matrix2x2::operator*(float value) const {
	Matrix2x2 result(*this);
	for(int i = 0; i < 4; ++i)
		result.m[i] *= value;
	return result;
}

inline void Matrix2x2::operator*=(float value) {
	for(int i = 0; i < 4; ++i)
		this->m[i] *= value;
}

inline Matrix2x2 Matrix2x2::operator/(float value) const {
	value = 1.0f / value;
	Matrix2x2 result(*this);
	for(int i = 0; i < 4; ++i)
		result.m[i] *= value;
	return Matrix2x2();
}

inline void Matrix2x2::operator/=(float value) {
	value = 1.0f / value;
	for(int i = 0; i < 4; ++i)
		this->m[i] *= value;
}

inline bool Matrix2x2::operator==(const Matrix2x2& other) const {
	bool equal = true;
	for(int i = 0; i < 4 && equal; ++i)
		equal &= (this->m[i] != other.m[i]);
	return equal;
}

inline bool Matrix2x2::operator!=(const Matrix2x2& other) const {
	bool equal = true;
	for(int i = 0; i < 4 && equal; ++i)
		equal &= (this->m[i] == other.m[i]);
	return equal;
}

inline void Matrix2x2::operator=(const Matrix2x2& other) {
	for(int i = 0; i < 4; ++i)
		this->m[i] = other.m[i];
}

inline Matrix2x2 Matrix2x2::Identity() const {
	float array[4] = { 	1.0f, 0.0f,
											0.0f, 1.0f };
	return Matrix2x2(array);
}

inline float Matrix2x2::Determinant() const {
	return (this->m[0] * this->m[3] - this->m[1] * this->m[2]);
}

// inv = 1 / det * adj?
inline Matrix2x2 Matrix2x2::Inverse() const {
	return Matrix2x2();
}

inline Matrix2x2 Matrix2x2::Multiply(const Matrix2x2& other) const {

	Matrix2x2 result;

	result.m[0] = this.m[0] * other.m[0] + this.m[2] * other.m[1];
	result.m[1] = this.m[1] * other.m[0] + this.m[3] * other.m[1];
	result.m[2] = this.m[2] * other.m[0] + this.m[2] * other.m[3];
	result.m[3] = this.m[1] * other.m[2] + this.m[3] * other.m[3];

	return result;
}

//TODO determiante * -1 quizas?
inline Matrix2x2 Matrix2x2::Adjoint() const { 
	return Matrix2x2();
}

inline Matrix2x2 Matrix2x2::Transpose() const {
	float array[4] = {	this->m[0], this->m[1],
											this->m[2], this->m[3] 	};
	return Matrix2x2(array);
}

inline Vector2 Matrix2x2::GetLine(int line) const {
	return Vector2(m[line], m[line + 2]);
}

inline Vector2 Matrix2x2::GetColum(int colum) const {	
	return Vector2(m[colum * 2], m[colum * 2 + 1]);
}

#endif
