
#ifndef __VECTOR3_H__
#define __VECTOR3_H__ 1

#include <math.h>

class Vector3 {

 public: 

 	Vector3();
 	Vector3(float value);
 	Vector3(float x, float y, float z);
 	Vector3(float* value_array);
 	Vector3(const Vector3& other);
 	~Vector3();

 	Vector3 operator+(const Vector3& other) const;
 	Vector3 operator+(float value) const;
 	Vector3& operator+=(const Vector3& other);
 	Vector3& operator+=(float value);
 	Vector3 operator-(const Vector3& othre) const;
 	Vector3 operator-(float value) const;
 	Vector3& operator-=(const Vector3& other);
 	Vector3& operator-=(float value);
 	Vector3 operator*(float value) const;
 	Vector3& operator*=(float value);
 	Vector3 operator/(float value) const;
 	Vector3& operator/=(float value);

 	bool operator==(const Vector3& other) const;
 	bool operator!=(const Vector3& other) const;
 	bool operator=(const Vector3& other) const;
 	bool operator=(float value);

 	float Magnitude() const;
 	float SqrMagnitude() const;

 	void Scale(float Vector3& other);
 	void Normalize();
 	Vector3 Normlaized() const;

 	static float DotProduct(const Vector3& a, const Vector3& b);
 	static float Distance(const Vector3& a, const Vector3& b);
 	static float Angle(const Vector3& a, const Vecto3& b)M

 	static Vector3 Lerp(const Vector3& a, const Vector3& b, float time);
 	static Vector3 LerpUnclamped(const Vector3& a, const Vector3& b, float time);
 	static Vector3 CrossProduct(const Vector3& a, const Vector3& b);
 	static Vector3 Reflect(const Vector3& direction, const Vector3& normal)

	static const Vector3 up;
	static const Vector3 down;
	static const Vector3 right;
	static const Vector3 left;
	static const Vector3 forward;
	static const Vector3 back;
	static const Vector3 zero;
	static const Vector3 unit;

	float x;
	float y;
	float z;

};

#endif // __VECTOR3_H__