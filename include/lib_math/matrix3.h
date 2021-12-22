#ifndef __MATRIX3_H__
#define __MATRIX3_H__ 1

#include "vector2.h"
#include "vector3.h"
#include "matrix2.h"
#include <stdio.h>
#include <stdint.h>

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

	static Vector2 Mat3TransformVec2(const Matrix3x3& mat, Vector2 vec);

	static Matrix3x3 Translate(const Vector2& position);
	static Matrix3x3 Translate(float x, float y);
	static Matrix3x3 Scale(float x, float y);
	static Matrix3x3 Rotate(float radians);

	Vector3 GetColum(int colum) const;
	Vector3 GetLine(int line) const;

	float m[9];

};

inline Matrix3x3::Matrix3x3() {
	for(int i = 0; i < 9; ++i)
		this->m[i] = 0.0f;
}
inline Matrix3x3::Matrix3x3(float value) {
	for(int i = 0; i < 9; ++i)
		this->m[i] = value;
}

inline Matrix3x3::Matrix3x3(float *values_array) {
	for(int i = 0; i < 9; ++i)
		this->m[i] = values_array[i];
}

inline Matrix3x3::Matrix3x3(Vector3 a, Vector3 b, Vector3 c) {
	this->m[0] = a.x;
	this->m[1] = a.y;
	this->m[2] = a.z;
	
	this->m[3] = b.x;
	this->m[4] = b.y;
	this->m[5] = b.z;
	
	this->m[6] = c.x;
	this->m[7] = c.y;
	this->m[8] = c.z;
}

inline Matrix3x3::Matrix3x3(const Matrix3x3& copy) {
	for(int i = 0; i < 9; ++i)
		this->m[i] = copy.m[i];
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
  for(int i = 0; i < 9; ++i)
    if(m[i] != other.m[i])
    	return false;
  return true;
}

inline bool Matrix3x3::operator!=(const Matrix3x3& other) const {
  for(int i = 0; i < 9; ++i)
    if(m[i] == other.m[i])
  		return false;
  return true;
}

inline void Matrix3x3::operator=(const Matrix3x3& other) {
	for(int i = 0; i < 9; ++i)
		this->m[i] = other.m[i];
	Matrix3x3(*this);
}

inline Matrix3x3 Matrix3x3::Identity(){
	float array[9] = { 	1.0f, 0.0f, 0.0f,
											0.0f, 1.0f, 0.0f,
											0.0f, 0.0f, 1.0f };
	return Matrix3x3(array);
}

inline float Matrix3x3::Determinant() const {
	//Sarrus
	return (	this->m[0] * this->m[4] * this->m[8] 
					+	this->m[3] * this->m[7] * this->m[2]
					+ this->m[1] * this->m[5] * this->m[6]
					- this->m[6] * this->m[4] * this->m[2]
					- this->m[0] * this->m[5] * this->m[7]
					- this->m[1] * this->m[3] * this->m[8]);
}

inline bool Matrix3x3::GetInverse(Matrix3x3& out) const {
	if(this->Determinant() != 0.0f){
		out = this->Adjoint() / this->Determinant();
		return true;
	}
	return false;
}

inline bool Matrix3x3::Inverse() {	
	if(this->Determinant() != 0.0f){
		*this = this->Adjoint() / this->Determinant();
		return true;
	}
	return false;
}

inline Vector2 Matrix3x3::Mat3TransformVec2(const Matrix3x3& mat, Vector2 vec){
	vec.x = {mat.m[0] * vec.x + mat.m[3] * vec.y + mat.m[6] * 1.0f };
	vec.y = {mat.m[1] * vec.x + mat.m[4] * vec.y + mat.m[7] * 1.0f };
	return vec;
}

inline Matrix3x3 Matrix3x3::Translate(const Vector2& mov_vector) {
	Matrix3x3 result = result.Identity();
	result.m[6] = mov_vector.x;
	result.m[7] = mov_vector.y; 
	return result;
}

inline Matrix3x3 Matrix3x3::Translate(float x, float y) { 
	Matrix3x3 result = result.Identity();
	result.m[6] = x; 
	result.m[7] = y; 
	return result;
}

inline Matrix3x3 Matrix3x3::Scale(float scale_x, float scale_y){
	Matrix3x3 result = result.Identity();
	result.m[0] = scale_x;
	result.m[4] = scale_y;
	return result;
}

inline Matrix3x3 Matrix3x3::Rotate(float radians){
	Matrix3x3 result = result.Identity();
	radians = radians * 3.14f / 180.0f;
	result.m[0] = cosf(radians);
	result.m[1] = -sinf(radians);
	result.m[3] = sinf(radians);
	result.m[4] = cosf(radians);
	return result;
}

inline Matrix3x3 Matrix3x3::Multiply(const Matrix3x3& other) const {
  Matrix3x3 result;
  unsigned int file = 0, colum = 0;
  for(int i = 0; i < 9; ++i){
    float temp = 0.0f;
    if(i % 3 == 0 && i != 0){ 
      file++; 
      colum = 0; 
    }
    for(int j = 0; j < 3; ++j){
      temp += this->m[file * 3 + j] * other.m[j * 3 + colum];
    }
    colum++;
    result.m[i] = temp;
  }
  return result;
}

inline Matrix3x3 Matrix3x3::Adjoint() const {
	
	float det_0[4] = { this->m[4], this->m[5], this->m[7], this->m[8] };
	float det_1[4] = { this->m[3], this->m[5], this->m[6], this->m[8] };
	float det_2[4] = { this->m[3], this->m[4], this->m[6], this->m[7] };

	float det_3[4] = { this->m[1], this->m[2], this->m[7], this->m[8] };
	float det_4[4] = { this->m[0], this->m[2], this->m[6], this->m[8] };
	float det_5[4] = { this->m[0], this->m[1], this->m[6], this->m[7] };

	float det_6[4] = { this->m[1], this->m[2], this->m[4], this->m[5] };
	float det_7[4] = { this->m[0], this->m[2], this->m[3], this->m[5] };
	float det_8[4] = { this->m[0], this->m[1], this->m[3], this->m[4] };

	float array[9] = { Matrix2x2(det_0).Determinant(), -Matrix2x2(det_1).Determinant(), Matrix2x2(det_2).Determinant(),
										 -Matrix2x2(det_3).Determinant(), Matrix2x2(det_4).Determinant(), -Matrix2x2(det_5).Determinant(),
										 Matrix2x2(det_6).Determinant(), -Matrix2x2(det_7).Determinant(), Matrix2x2(det_8).Determinant() };

	return Matrix3x3(array);
}

inline Matrix3x3 Matrix3x3::Transpose() const {
	float array[9] = {  this->m[0], this->m[3], this->m[6],
											this->m[1], this->m[4], this->m[7],
											this->m[2], this->m[5], this->m[8] };
	return Matrix3x3(array);
}

inline Vector3 Matrix3x3::GetColum(int colum) const {
	return Vector3(m[colum], m[colum + 3], m[colum + 6]);
}

inline Vector3 Matrix3x3::GetLine(int line) const {
	return Vector3(m[line * 3], m[line * 3 + 1], m[line * 3 + 2]);
}

#endif 