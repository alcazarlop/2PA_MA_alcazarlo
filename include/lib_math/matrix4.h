#ifndef __MATRIX4_H__
#define __MATRIX4_H__ 1

#include "vector3.h"
#include "vector4.h"
#include "matrix3.h"
#include <math.h>

class Matix4x4{
	
 public:

  Matix4x4();
  Matix4x4(float a[16]);
  Matix4x4(float value);
  Matix4x4(const Matix4x4& copy);
  ~Matix4x4();

  Matix4x4 operator+(const Matix4x4& other) const;
  Matix4x4& operator+=(const Matix4x4& other);
  Matix4x4 operator+(float value) const;
  Matix4x4& operator+=(float value);
  Matix4x4 operator-(const Matix4x4& other) const;
  Matix4x4& operator-=(const Matix4x4& other);
  Matix4x4 operator-(float value) const;
  Matix4x4& operator-=(float value);
  Matix4x4& operator*=(float value);
  Matix4x4 operator*(float value) const;
  Matix4x4& operator/=(float value);
  Matix4x4 operator/(float value) const;
  bool operator==(const Matix4x4& other);
  bool operator!=(const Matix4x4& other);
  void operator=(const Matix4x4& other);

  float Determinant() const;
  
  Matix4x4 Identity() const;
  Matix4x4 Multiply(const Matix4x4& other) const;
  Matix4x4 Adjoint() const;
  Matix4x4 Transpose() const;

  bool GetInverse(Matix4x4* out) const;
  bool Inverse();

  static Matix4x4 Translate(const Vector3& distance);
  static Matix4x4 Translate(float x, float y, float z);

  static Matix4x4 Scale(const Vector3& scale);
  static Matix4x4 Scale(float x, float y, float z);

  static Matix4x4 RotateX(float radians);
  static Matix4x4 RotateY(float radians);
  static Matix4x4 RotateZ(float radians);

  static Matix4x4 GetTransform(const Vector3& translate, const Vector3& scale,
                      float rotateX, float rotateY, float rotateZ);

  static Matix4x4 GetTransform(float trans_x, float trans_y, float trans_z,
                      float scale_x, float scale_y, float scale_Z,
                      float rotateX, float rotateY, float rotateZ);

  Matix4x4 PerspectiveMatrix(float fov, float aspect,
	  float near, float far) const;

  Matix4x4 OrthoMatrix(float right, float left, float top, float bottom,
	  float near, float far) const;

  Vector4 GetColum(int colum) const;
  Vector4 GetLine(int line) const;

  float m[16];

};

inline Matix4x4::Matix4x4() {
  m[0] = 0.0f; m[4] = 0.0f; m[8] = 0.0f; m[12] = 0.0f;
  m[1] = 0.0f; m[5] = 0.0f; m[9] = 0.0f; m[13] = 0.0f;
  m[2] = 0.0f; m[6] = 0.0f; m[10] = 0.0f; m[14] = 0.0f;
  m[3] = 0.0f; m[7] = 0.0f; m[11] = 0.0f; m[15] = 0.0f;
}

inline Matix4x4::Matix4x4(float array[16]) {
  m[0] = array[0]; m[4] = array[4]; m[8] = array[8]; m[12] = array[12];
  m[1] = array[1]; m[5] = array[5]; m[9] = array[9]; m[13] = array[13];
  m[2] = array[2]; m[6] = array[6]; m[10] = array[10]; m[14] = array[14];
  m[3] = array[3]; m[7] = array[7]; m[11] = array[11]; m[15] = array[15];
}

inline Matix4x4::Matix4x4(float value) {
  m[0] = value; m[4] = value; m[8] = value; m[12] = value;
  m[1] = value; m[5] = value; m[9] = value; m[13] = value;
  m[2] = value; m[6] = value; m[10] = value; m[14] = value;
  m[3] = value; m[7] = value; m[11] = value; m[15] = value;
}

inline Matix4x4::Matix4x4(const Matix4x4& copy) {
  m[0] = copy.m[0]; m[4] = copy.m[4]; m[8] = copy.m[8]; m[12] = copy.m[12];
  m[1] = copy.m[1]; m[5] = copy.m[5]; m[9] = copy.m[9]; m[13] = copy.m[13];
  m[2] = copy.m[2]; m[6] = copy.m[6]; m[10] = copy.m[10]; m[14] = copy.m[14];
  m[3] = copy.m[3]; m[7] = copy.m[7]; m[11] = copy.m[11]; m[15] = copy.m[15];
}

inline Matix4x4::~Matix4x4() {}

inline Matix4x4 Matix4x4::Identity() const {
  float array[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::Multiply(const Matix4x4& other) const {

  Matix4x4 result;

  result.m[0] = this->m[0] * other.m[0] + this->m[1] * other.m[4] + this->m[2] * other.m[8] + this->m[3] * other.m[12];
  result.m[1] = this->m[0] * other.m[1] + this->m[1] * other.m[5] + this->m[2] * other.m[9] + this->m[3] * other.m[13];
  result.m[2] = this->m[0] * other.m[2] + this->m[1] * other.m[6] + this->m[2] * other.m[10] + this->m[3] * other.m[14];
  result.m[3] = this->m[0] * other.m[3] + this->m[1] * other.m[7] + this->m[2] * other.m[11] + this->m[3] * other.m[15];

  result.m[4] = this->m[4] * other.m[0] + this->m[5] * other.m[4] + this->m[6] * other.m[8] + this->m[7] * other.m[12];
  result.m[5] = this->m[4] * other.m[1] + this->m[5] * other.m[5] + this->m[6] * other.m[9] + this->m[7] * other.m[13];
  result.m[6] = this->m[4] * other.m[2] + this->m[5] * other.m[6] + this->m[6] * other.m[10] + this->m[7] * other.m[14];
  result.m[7] = this->m[4] * other.m[3] + this->m[5] * other.m[7] + this->m[6] * other.m[11] + this->m[7] * other.m[15];

  result.m[8] = this->m[8] * other.m[0] + this->m[9] * other.m[4] + this->m[10] * other.m[8] + this->m[11] * other.m[12];
  result.m[9] = this->m[8] * other.m[1] + this->m[9] * other.m[5] + this->m[10] * other.m[9] + this->m[11] * other.m[13];
  result.m[10] = this->m[8] * other.m[2] + this->m[9] * other.m[6] + this->m[10] * other.m[10] + this->m[11] * other.m[14];
  result.m[11] = this->m[8] * other.m[3] + this->m[9] * other.m[7] + this->m[10] * other.m[11] + this->m[11] * other.m[15];

  result.m[12] = this->m[12] * other.m[0] + this->m[13] * other.m[4] + this->m[14] * other.m[8] + this->m[15] * other.m[12];
  result.m[13] = this->m[12] * other.m[1] + this->m[13] * other.m[5] + this->m[14] * other.m[9] + this->m[15] * other.m[13];
  result.m[14] = this->m[12] * other.m[2] + this->m[13] * other.m[6] + this->m[14] * other.m[10] + this->m[15] * other.m[14];
  result.m[15] = this->m[12] * other.m[3] + this->m[13] * other.m[7] + this->m[14] * other.m[11] + this->m[15] * other.m[15];

  return result;
}


inline float Matix4x4::Determinant() const {
  
  return 0.0f;
}


inline Matix4x4 Matix4x4::Adjoint() const {
  
  Matix4x4 result;
  return result;
}

inline bool Matix4x4::Inverse() {
  return true;
}

inline bool Matix4x4::GetInverse(Matix4x4* out) const {
  return true;

}

inline Matix4x4 Matix4x4::Transpose() const {
  float array[16] = { this->m[0], this->m[1], this->m[2], this->m[3],
                      this->m[4], this->m[5], this->m[6], this->m[7],
                      this->m[8], this->m[9], this->m[10], this->m[11],
                      this->m[12], this->m[13], this->m[14], this->m[15] };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::Translate(const Vector3& distance){
  float array[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, 1.0f, 0.0f,
                      distance.x, distance.y, distance.z ,1.0f };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::Translate(float x, float y, float z){
  float array[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, 1.0f, 0.0f,
                      x, y, z, 1.0f         };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::Scale(const Vector3& scale){
  float array[16] = { scale.x, 0.0f, 0.0f, 0.0f,
                    0.0f, scale.y, 0.0f, 0.0f,
                    0.0f, 0.0f, scale.z, 0.0f,
                    0.0f, 0.0f, 0.0f, 0.0f    };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::Scale(float x, float y, float z){
 float array[16] = { x, 0.0f, 0.0f, 0.0f,
                    0.0f, y, 0.0f, 0.0f,
                    0.0f, 0.0f, z, 0.0f,
                    0.0f, 0.0f, 0.0f, 0.0f };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::RotateX(float radians){
  float array[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
                      0.0f, cosf(radians), sinf(radians), 0.0f,
                      0.0f, -sinf(radians), cosf(radians), 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::RotateY(float radians){
  float array[16] = { cosf(radians), 0.0f, -sinf(radians), 0.0f,
                      0.0f, 1.0f, 0.0f, 0.0f,
                      sinf(radians), 0.0f, cosf(radians), 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::RotateZ(float radians) {
  float array[16] = { cosf(radians), sinf(radians), 0.0f, 0.0f,
                      -sinf(radians), cosf(radians), 0.0f ,0.0f, 
                      0.0f, 0.0f, 1.0f, 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::GetTransform(const Vector3& translate,
                const Vector3& scale,
                float rotateX, float rotateY,
                float rotateZ)   {

  return Matix4x4();
}

inline Matix4x4 Matix4x4::GetTransform(float trans_x, float trans_y, float trans_z,
  float scale_x, float scale_y, float scale_z,
  float rotateX, float rotateY, float rotateZ)  {

  // Matix4x4 result;
  // Matix4x4 translation;
  // Matix4x4 scalation;
  // Matix4x4 rotation;

  // rotation = rotation.RotateX(rotateX).Multiply(rotation.RotateY(rotateY).Multiply(rotation.RotateZ(rotateZ)));
  // result = translation.Translate(trans_x, trans_y, trans_z).Multiply(rotation.Multiply(scalation.Scale(scale_x, scale_y, scale_z)));
  
  return Matix4x4();
}

inline Vector4 Matix4x4::GetColum(int colum) const {
  return Vector4();
}

inline Vector4 Matix4x4::GetLine(int line) const {
  return Vector4();
}

inline Matix4x4 Matix4x4::PerspectiveMatrix(float fov, float aspect,
  float near, float far) const {
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::OrthoMatrix(float right, float left, float top, float bottom,
  float near, float far) const {

  return Matix4x4();
}

inline Matix4x4 Matix4x4::operator+(const Matix4x4& other) const {
  Matix4x4 result(*this);
  for(int i = 0; i < 16; ++i)
    result.m[i] += other.m[i];
  return result;
}

inline Matix4x4& Matix4x4::operator+=(const Matix4x4& other) {
  for(int i = 0; i < 16; ++i)
    m[i] += other.m[i];
  return *this;
}

inline Matix4x4 Matix4x4::operator+(float value) const {
  Matix4x4 result(*this);
  for(int i = 0; i < 16; ++i)
    result.m[i] += value;
  return result;
}

inline Matix4x4& Matix4x4::operator+=(float value) { 
  for(int i = 0; i < 16; ++i)
    m[i] += value;
  return *this; 
}

inline Matix4x4 Matix4x4::operator-(const Matix4x4& other) const  {
  Matix4x4 result(*this);
  for(int i = 0; i < 16; ++i)
    result.m[i] -= other.m[i];
  return result;
}

inline Matix4x4& Matix4x4::operator-=(const Matix4x4& other) {
  for(int i = 0; i < 16; ++i)
    m[i] -= other.m[i];
  return *this;
}

inline Matix4x4 Matix4x4::operator-(float value) const  {
  Matix4x4 result;
  for(int i = 0; i < 16; ++i)
    result.m[i] -= value;
  return result;
}

inline Matix4x4& Matix4x4::operator-=(float value) {
  for(int i = 0; i < 16; ++i)
    m[i] -= value;
  return *this;
}

inline Matix4x4& Matix4x4::operator*=(float value) {
  for(int i = 0; i < 16; ++i)
    m[i] *= value;
  return *this;
}

inline Matix4x4 Matix4x4::operator*(float value) const  {
  Matix4x4 result(*this);
  for(int i = 0; i < 16; ++i)
    result.m[i] *= value;
  return result;
}

inline Matix4x4& Matix4x4::operator/=(float value) {
  value = 1.0f / value;
  for(int i = 0; i < 16; ++i)
    m[i] *= value;
  return *this;
}

inline Matix4x4 Matix4x4::operator/(float value) const {
  value = 1.0f / value;
  Matix4x4 result;
  for(int i = 0; i < 16; ++i)
    result.m[i] *= value;
  return result;
}

inline bool Matix4x4::operator==(const Matix4x4& other) {
  return true;
}

inline bool Matix4x4::operator!=(const Matix4x4& other) {
  return false;
}

inline void Matix4x4::operator=(const Matix4x4& other) {

}


#endif
