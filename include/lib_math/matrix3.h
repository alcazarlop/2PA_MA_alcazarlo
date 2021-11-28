#ifndef __MATRIX3_H__
#define __MATRIX3_H__ 1

#include "vector2.h"
#include "vector3.h"

class Matrix3x3 {

 public:

	Matrix3x3();
	Matrix3x3(float *values_array);
	Matrix3x3(float value);
	Matrix3x3(Vector3 a, Vector3 b, Vector3 c);

	Matrix3x3(const Matrix3x3& copy);
	~Matrix3x3();

	Matrix3x3 operator+(const Matrix3x3& other) const;
	Matrix3x3& operator+=(const Matrix3x3& other);
	Matrix3x3 operator+(float value) const;
	Matrix3x3& operator+=(float value);
	Matrix3x3 operator-(const Matrix3x3& other) const;
	Matrix3x3& operator-=(const Matrix3x3& other);
	Matrix3x3 operator-(float value) const;
	Matrix3x3& operator-=(float value);
	Matrix3x3 operator*(float value) const;
	Matrix3x3& operator*=(float value);
	Matrix3x3 operator/(float value) const;
	Matrix3x3& operator/=(float value);
	bool operator==(const Matrix3x3& other) const;
	bool operator!=(const Matrix3x3& other) const;
	void operator=(const Matrix3x3& other);

	static Matrix3x3 Identity();

	float Determinant() const;

	Matrix3x3 Multiply(const Matrix3x3& other) const;
	Matrix3x3 Adjoint() const;
	Matrix3x3 Transpose() const;

	bool GetInverse(Matrix3x3& out) const;
	bool Inverse();

	static Matrix3x3 Translate(const Vector2& position);
	static Matrix3x3 Translate(float x, float y);

	Vector3 GetColum(int colum) const;
	Vector3 GetLine(int line) const;

	float m[9];

};

inline Matrix3x3::Matrix3x3() {
	for(int i = 0; i < 9; ++i)
		m[i] = 0.0f;
}
inline Matrix3x3::Matrix3x3(float value) {
	for(int i = 0; i < 9; ++i)
		m[i] = value;
}

inline Matrix3x3::Matrix3x3(float *values_array) {
	for(int i = 0; i < 9; ++i)
		m[i] = values_array[i];
}

inline Matrix3x3::Matrix3x3(Vector3 a, Vector3 b, Vector3 c) {

}

inline Matrix3x3::Matrix3x3(const Matrix3x3& copy) {
	for(int i = 0; i < 9; ++i)
		m[i] = copy.m[i];
}

inline Matrix3x3::~Matrix3x3() {}

inline Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const {
	Matrix3x3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] += other.m[i];
	return result;
}

inline Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& other) {
	for(int i = 0; i < 9; ++i)
		m[i] += other.m[i];
	return *this;
}

inline Matrix3x3 Matrix3x3::operator+(float value) const {
	Matrix3x3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] += value;
	return result;
}

inline Matrix3x3& Matrix3x3::operator+=(float value) {
	for(int i = 0; i < 9; ++i)
		m[i] += value;
	return *this;
}

inline Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const {
	Matrix3x3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] -= other.m[i];
	return result;
}

inline Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& other) {
	for(int i = 0; i < 9; ++i)
		m[i] -= other.m[i];
	return *this;
}

inline Matrix3x3 Matrix3x3::operator-(float value) const {
	Matrix3x3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] -= value;
	return result;
}

inline Matrix3x3& Matrix3x3::operator-=(float value) {
	for(int i = 0; i < 9; ++i)
		m[i] -= value;
	return *this;
}

inline Matrix3x3 Matrix3x3::operator*(float value) const {
	Matrix3x3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] *= value;
	return result;
}

inline Matrix3x3& Matrix3x3::operator*=(float value) {
	for(int i = 0; i < 9; ++i)
		m[i] *= value;
	return *this;
}

inline Matrix3x3 Matrix3x3::operator/(float value) const {
	value = 1.0f / value;
	Matrix3x3 result(*this);
	for(int i = 0; i < 9; ++i)
		result.m[i] *= value;
	return result;
}

inline Matrix3x3& Matrix3x3::operator/=(float value) {
	value = 1.0f / value;
	for(int i = 0; i < 9; ++i)
		m[i] *= value;
	return *this;
}

inline bool Matrix3x3::operator==(const Matrix3x3& other) const {
	return true;
}

inline bool Matrix3x3::operator!=(const Matrix3x3& other) const {
	return true;
}

inline void Matrix3x3::operator=(const Matrix3x3& other) {
}

inline Matrix3x3 Matrix3x3::Identity(){
	// for(int i = 0; i < 3; ++i)
	// 	for(int j = 0; j < 3; ++j)
	// 		if(j == i)
	// 			m[(j + i + 2)] = 1.0f;

	return Matrix3x3();
}

inline float Matrix3x3::Determinant() const {
	return 0.0f;
}

inline bool Matrix3x3::GetInverse(Matrix3x3& out) const {
	return true;
}

inline bool Matrix3x3::Inverse() {	
	return true;
}

inline Matrix3x3 Matrix3x3::Translate(const Vector2& mov_vector) {	
	return Matrix3x3();
}

inline Matrix3x3 Matrix3x3::Translate(float x, float y) {
	return Matrix3x3();
}

inline Matrix3x3 Matrix3x3::Multiply(const Matrix3x3& other) const {
	return Matrix3x3();
}

inline Matrix3x3 Matrix3x3::Adjoint() const {
	return Matrix3x3();
}

inline Matrix3x3 Matrix3x3::Transpose() const {
	return Matrix3x3();
}

inline Vector3 Matrix3x3::GetColum(int colum) const {
	return Vector3(m[colum], m[colum + 3], m[colum + 6]);
}

inline Vector3 Matrix3x3::GetLine(int line) const {
	return Vector3(m[line], m[line + 1], m[line + 2]);
}

#endif 