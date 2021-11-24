#ifndef __MATRIX3_H__
#define __MATRIX3_H__ 1

#include "vector_2.h"
#include "vector_3.h"

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

#endif 