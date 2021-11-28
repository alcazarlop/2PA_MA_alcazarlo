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
	Vector2 GetColum(int line) const;

	Matrix2x2 Identity() const;
	Matrix2x2 Multiply(const Matrix2x2& other) const;
	Matrix2x2 Adjoint() const;
	Matrix2x2 Inverse() const;
	Matrix2x2 Transpose() const;

	float m[4];

};

inline Matrix2x2::Matrix2x2() {
	m[0] = 0; 
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
}

inline Matrix2x2::Matrix2x2(float a[4]) {
	m[0] = a[0];
	m[1] = a[1];
	m[2] = a[2];
	m[3] = a[3];
}

inline Matrix2x2::Matrix2x2(float a) {
	m[0] = a;
	m[1] = a;
	m[2] = a;
	m[3] = a;
}

inline Matrix2x2::Matrix2x2(const Vector2& a, const Vector2& b) {
	m[0] = a.x;
	m[1] = a.y;
	m[2] = b.y;
	m[3] = b.y;
}

inline Matrix2x2::Matrix2x2(const Matrix2x2& copy) {
	m[0] = copy[0];
	m[1] = copy[1];
	m[2] = copy[2];
	m[3] = copy[3];
}

inline Matrix2x2::~Matrix2x2() { }

inline Matrix2x2 Matrix2x2::operator+(const Matrix2x2& other) const {
	return Matrix2x2();
}

inline void Matrix2x2::operator+=(const Matrix2x2& other) {
}

inline Matrix2x2 Matrix2x2::operator+(float value) const {
	return Matrix2x2();
}

inline void Matrix2x2::operator+=(float value) {
}

inline Matrix2x2 Matrix2x2::operator-(const Matrix2x2& other) const {
	return Matrix2x2();
}

inline void Matrix2x2::operator-=(const Matrix2x2& other) {
}

inline Matrix2x2 Matrix2x2::operator-(float value) const {	
	return Matrix2x2();
}

inline void Matrix2x2::operator-=(float value) {
}


inline Matrix2x2 Matrix2x2::operator*(float value) const {
	return Matrix2x2();
}

inline void Matrix2x2::operator*=(float value) {



}

inline Matrix2x2 Matrix2x2::operator/(float value) const {
	return Matrix2x2();
}

inline void Matrix2x2::operator/=(float value) {
}


inline bool Matrix2x2::operator==(const Matrix2x2& other) const {
	return true;
}

inline bool Matrix2x2::operator!=(const Matrix2x2& other) const {
	return true;
}

inline void Matrix2x2::operator=(const Matrix2x2& other) {
}

inline Matrix2x2 Matrix2x2::Identity() const {
	return Matrix2x2();
}

inline float Matrix2x2::Determinant() const {
	return 0.0f;
}

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

inline Matrix2x2 Matrix2x2::Adjoint() const {
	return Matrix2x2();
}

inline Matrix2x2 Matrix2x2::Transpose() const {
	return Matrix2x2();
}

inline Vector2 Matrix2x2::GetLine(int line) const {
	return Vector2();
}

inline Vector2 Matrix2x2::GetColum(int line) const {	
	return Vector2();
}

#endif
