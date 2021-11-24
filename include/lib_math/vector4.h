
#ifndef __VECTOR4_H__
#define __VECTOR4_H__ 1

#include "vector3.h"
#include <math.h>

class Vector4 {

 public:

 	Vector4();
 	Vector4(float x, float y, float z, float w);
 	Vector4(Vector3 other, float w);
 	Vector4(float value);
 	Vector4(float* values_array);
 	Vector4(const Vector4& other);
 	~Vector4();

 	Vector4 operator+(const Vector4& other) const;
 	Vector4 operator+(float value) const;
 	void operator+=(const Vector4& other);
 	void operator+=(float value);
 	Vector4 operator-(const Vecto4& other) const;
 	Vector4 operator-(float value) const;
 	void operator-=(const Vector4& other);
 	void operator-=(float value);
 	Vector4 operator*(float value) const;
 	void operator*=(float value);
 	Vector4 operator/(float value) const;
 	void operator/=(float value);

 	bool operator==(const Vector4& other);
 	bool operator!=(const Vector4& other);
 	void operator=(const Vector4& other);

 	float Magnitude() const;
 	void Normalize();
 	Vector4 Normalized() const;

 	void Scale(Vector4 scale);
 	float SqrMagnitude() const;

 	static float Distance(const Vector4& a, const Vector4& b);
 	static float DotProduct(Vector4 a, Vector4 b);
 	static Vector4 Lerp(const Vector4& a, const Vector4& b, float time);

 	static const Vector4 one;
 	static const Vector4 zero;

 	float x;
 	float y;
 	float z;
 	float w;

};


#endif //__VECTOR4_H__