#ifndef __MATRIX2_H__
#define __MATRIX2_H__ 1

#include "vector_2.h"

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

#endif
