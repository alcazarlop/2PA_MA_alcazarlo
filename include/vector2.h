
#ifndef __VECTOR2_H__
#define __VECTOR2_H__ 1

#include <math.h>

class Vector2 {

 public:
	
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& copy);	
	~Vector2();

	Vector2 operator+(const Vector2& other) const; 	
	Vector2 operator+(float value); 	
	Vector2& operator+=(const Vector2& other);
	Vector2& operator+=(float value);
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-(float value) const;
	Vector2& operator-();
	Vector2& operator-=(const Vector2& other);
	Vector2& operator-=(float value);
	Vector2 operator*(float value) const;
	Vector2& operator*=(float value);
	Vector2 operator/(float value) const;
	Vector2& operator/=(float value);

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;
	void operator=(const Vector2& other);
	void operator=(float value);

	float Magnitude() const;
	float SqrMagnitude() const;

	void Scale(const Vector2 scale);
	void Normalize();
	Vector2 Normalized() const;

	static float Distnace(const Vector2 a, const Vector2 b);
	static float DotProduct(const Vector2 a, const Vector2 b);

	static Vector2 Lerp(const Vector2, const Vector2, float time);
	static Vector2 LerpUnclamped(const Vector2, const Vector2, float time);

  static const Vector2 up;
  static const Vector2 down;
  static const Vector2 right;
  static const Vector2 left;
  static const Vector2 zero;
  static const Vector2 one;

	float x;
	float y;

};

#endif // __VECTOR2_H__
