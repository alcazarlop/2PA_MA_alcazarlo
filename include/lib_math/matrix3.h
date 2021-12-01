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
	m[0] = 0.0f; m[3] = 0.0f; m[6] = 0.0f;
	m[1] = 0.0f; m[4] = 0.0f; m[7] = 0.0f;
	m[2] = 0.0f; m[5] = 0.0f; m[8] = 0.0f;
}
inline Matrix3x3::Matrix3x3(float value) {
	m[0] = value; m[3] = value; m[6] = value;
	m[1] = value; m[4] = value; m[7] = value;
	m[2] = value; m[5] = value; m[8] = value;
}

inline Matrix3x3::Matrix3x3(float *values_array) {
	m[0] = values_array[0]; m[3] = values_array[3]; m[6] = values_array[6];
	m[1] = values_array[1]; m[4] = values_array[4]; m[7] = values_array[7];
	m[2] = values_array[2]; m[5] = values_array[5]; m[8] = values_array[8];
}

inline Matrix3x3::Matrix3x3(Vector3 a, Vector3 b, Vector3 c) {
	m[0] = a.x; m[3] = a.y; m[6] = a.z;
	m[1] = b.x; m[4] = b.y; m[7] = b.z;
	m[2] = c.x; m[5] = c.y; m[8] = c.z;
}

inline Matrix3x3::Matrix3x3(const Matrix3x3& copy) {
	m[0] = copy.m[0]; m[3] = copy.m[3]; m[6] = copy.m[6];
	m[1] = copy.m[1]; m[4] = copy.m[4]; m[7] = copy.m[7];
	m[2] = copy.m[2]; m[5] = copy.m[5]; m[8] = copy.m[8];
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
	float array[9] = { 	1.0f, 0.0f, 0.0f,
											0.0f, 1.0f, 0.0f,
											0.0f, 0.0f, 1.0f };
	return Matrix3x3(array);
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
	float array[9] = {	1.0f, 0.0f, 0.0f,
											0.0f, 1.0f, 0.0f,
											mov_vector.x, mov_vector.y, 1.0f };
	return Matrix3x3(array);
}

inline Matrix3x3 Matrix3x3::Translate(float x, float y) {
	float array[9] = {	1.0f, 0.0f, 0.0f,
											0.0f, 1.0f, 0.0f,
											x, y, 1.0f };
	return Matrix3x3(array);
}

inline Matrix3x3 Matrix3x3::Multiply(const Matrix3x3& other) const {
	
	Matrix3x3 result(0.0f,0.0f,0.0f);
	
	// result.m[0] = this->m[0] * other.m[0] + this->m[1] * other.m[3] + this->m[2] * other.m[6];
	// result.m[1] = this->m[0] * other.m[1] + this->m[1] * other.m[4] + this->m[2] * other.m[7];
	// result.m[2] = this->m[0] * other.m[2] + this->m[1] * other.m[5] + this->m[2] * other.m[8];
	
	// result.m[3] = this->m[3] * other.m[0] + this->m[4] * other.m[3] + this->m[5] * other.m[6];
	// result.m[4] = this->m[3] * other.m[1] + this->m[4] * other.m[4] + this->m[5] * other.m[7];
	// result.m[5] = this->m[3] * other.m[2] + this->m[4] * other.m[5] + this->m[5] * other.m[8];

	// result.m[6] = this->m[6] * other.m[0] + this->m[7] * other.m[3] + this->m[8] * other.m[6];
	// result.m[7] = this->m[6] * other.m[1] + this->m[7] * other.m[4] + this->m[8] * other.m[7];
	// result.m[8] = this->m[6] * other.m[2] + this->m[7] * other.m[5] + this->m[8] * other.m[8];
	
	return result;
}


inline Matrix3x3 Matrix3x3::Adjoint() const {
	return Matrix3x3();
}

inline Matrix3x3 Matrix3x3::Transpose() const {
float array[9] = {  this->m[0], this->m[3], this->m[6],
										this->m[1], this->m[4], this->m[7],
										this->m[2], this->m[5], this->m[8] };
	return Matrix3x3(array);
}

inline Vector3 Matrix3x3::GetColum(int colum) const {
	return Vector3();
}

inline Vector3 Matrix3x3::GetLine(int line) const {
	return Vector3();
}

#endif 