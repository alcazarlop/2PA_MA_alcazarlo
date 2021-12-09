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
  for(int i = 0; i < 16; ++i)
    this->m[i] = 0.0f;
}

inline Matix4x4::Matix4x4(float array[16]) {
  for(int i = 0; i < 16; ++i)
    this->m[i] = array[i];
}

inline Matix4x4::Matix4x4(float value) {
  for(int i = 0; i < 16; ++i)
    this->m[i] = value;
}

inline Matix4x4::Matix4x4(const Matix4x4& copy) {
  for(int i = 0; i < 16; ++i)
    this->m[i] = copy.m[i];
}

inline Matix4x4::~Matix4x4() {}

inline Matix4x4 Matix4x4::Identity() const {
  float array[16] = { 1.0f, 0.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, 1.0f, 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f };
  return Matix4x4(array); 
}

inline Matix4x4 Matix4x4::Multiply(const Matix4x4& other) const {
  Matix4x4 result;
  unsigned int file = 0, colum = 0;
  for(int i = 0; i < 16; ++i){
    float temp = 0.0f;
    if(i % 4 == 0 && i != 0){ 
      file++; 
      colum = 0; 
    }
    for(int j = 0; j < 4; ++j){
      temp += this->m[file * 4 + j] * other.m[j * 4 + colum];
    }
    colum++;
    result.m[i] = temp;
  }
  return result;
}


inline float Matix4x4::Determinant() const {
  
  float det_0[9] = { this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_1[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_2[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[7], this->m[11], this->m[15] };

  float det_3[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14] };

  return (  this->m[0] * Matrix3x3(det_0).Determinant() - this->m[1] * Matrix3x3(det_1).Determinant() 
          + this->m[2] * Matrix3x3(det_2).Determinant() - this->m[3] * Matrix3x3(det_3).Determinant());
}


inline Matix4x4 Matix4x4::Adjoint() const {
  
  float det_0[9] = { this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_1[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[6], this->m[10], this->m[14],
                     this->m[7], this->m[11], this->m[15] };

  float det_2[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[7], this->m[11], this->m[15] };

  float det_3[9] = { this->m[4], this->m[8], this->m[12],
                     this->m[5], this->m[9], this->m[13],
                     this->m[6], this->m[10], this->m[14] };

  float det_4[9] = { this->m[1], this->m[9], this->m[13],
                     this->m[2], this->m[10], this->m[14],
                     this->m[3], this->m[11], this->m[15] };

  float det_5[9] = { this->m[0], this->m[8], this->m[12],
                     this->m[2], this->m[10], this->m[14],
                     this->m[3], this->m[11], this->m[15] };

  float det_6[9] = { this->m[0], this->m[8], this->m[12],
                     this->m[1], this->m[9], this->m[13],
                     this->m[3], this->m[11], this->m[15] };

  float det_7[9] = { this->m[0], this->m[8], this->m[12],
                     this->m[1], this->m[9], this->m[13],
                     this->m[2], this->m[10], this->m[14] };  

  float det_8[9] = { this->m[1], this->m[5], this->m[13],
                     this->m[2], this->m[6], this->m[14],
                     this->m[3], this->m[7], this->m[15] };

  float det_9[9] = { this->m[0], this->m[4], this->m[12],
                     this->m[2], this->m[6], this->m[14],
                     this->m[3], this->m[7], this->m[15] };

  float det_10[9] = { this->m[0], this->m[4], this->m[12],
                     this->m[1], this->m[5], this->m[13],
                     this->m[3], this->m[7], this->m[15] };

  float det_11[9] = { this->m[0], this->m[4], this->m[12],
                     this->m[1], this->m[5], this->m[13],
                     this->m[2], this->m[6], this->m[14] };  

  float det_12[9] = { this->m[1], this->m[5], this->m[9],
                     this->m[2], this->m[6], this->m[10],
                     this->m[3], this->m[7], this->m[11] };

  float det_13[9] = { this->m[0], this->m[4], this->m[8],
                     this->m[2], this->m[6], this->m[10],
                     this->m[3], this->m[7], this->m[11] };

  float det_14[9] = { this->m[0], this->m[4], this->m[8],
                     this->m[1], this->m[5], this->m[9],
                     this->m[3], this->m[7], this->m[11] };

  float det_15[9] = { this->m[0], this->m[4], this->m[8],
                     this->m[1], this->m[5], this->m[9],
                     this->m[2], this->m[6], this->m[10] };

  float array[16] = { Matrix3x3(det_0).Determinant(), -Matrix3x3(det_4).Determinant(), Matrix3x3(det_8).Determinant(), -Matrix3x3(det_12).Determinant(),
                      -Matrix3x3(det_1).Determinant(), Matrix3x3(det_5).Determinant(), -Matrix3x3(det_9).Determinant(), Matrix3x3(det_13).Determinant(),
                      Matrix3x3(det_2).Determinant(), -Matrix3x3(det_6).Determinant(), Matrix3x3(det_10).Determinant(), -Matrix3x3(det_14).Determinant(),
                      -Matrix3x3(det_3).Determinant(), Matrix3x3(det_7).Determinant(),- Matrix3x3(det_11).Determinant(), Matrix3x3(det_15).Determinant() };  

  return Matix4x4(array).Transpose();
}

inline bool Matix4x4::Inverse() {
  if(this->Determinant() != 0.0f){
    *this = this->Adjoint() / this->Determinant();
      return true;
  }
  return false;
}

inline bool Matix4x4::GetInverse(Matix4x4* out) const {
 if(this->Determinant() != 0.0f){
    *out = this->Adjoint() / this->Determinant();
      return true;
  }
  return false;
}

inline Matix4x4 Matix4x4::Transpose() const {
  float array[16] = { this->m[0], this->m[4], this->m[8], this->m[12],
                      this->m[1], this->m[5], this->m[9], this->m[13],
                      this->m[2], this->m[6], this->m[10], this->m[14],
                      this->m[3], this->m[7], this->m[11], this->m[15] };
  return Matix4x4(array);
}

inline Matix4x4 Matix4x4::Translate(const Vector3& distance){
  Matix4x4 result = result.Identity();
  result.m[12] = distance.x;
  result.m[13] = distance.y;
  result.m[14] = distance.z;
  return result;
}

inline Matix4x4 Matix4x4::Translate(float x, float y, float z){
  Matix4x4 result = result.Identity();
  result.m[12] = x;
  result.m[13] = y;
  result.m[14] = z;
  return result;
}

inline Matix4x4 Matix4x4::Scale(const Vector3& scale){
  Matix4x4 result = result.Identity();
  result.m[0] = scale.x;
  result.m[5] = scale.y;
  result.m[10] = scale.z;
  return result;
}

inline Matix4x4 Matix4x4::Scale(float x, float y, float z){
  Matix4x4 result = result.Identity();
  result.m[0] = x;
  result.m[5] = y;
  result.m[10] = z;
  return result;
}

inline Matix4x4 Matix4x4::RotateX(float radians){
  Matix4x4 result = result.Identity();
  result.m[5] = cosf(radians);
  result.m[6] = -sinf(radians);
  result.m[9] = sinf(radians);
  result.m[10] = cosf(radians);
  return result;
}

inline Matix4x4 Matix4x4::RotateY(float radians){
  Matix4x4 result = result.Identity();
  result.m[0] = cosf(radians);
  result.m[2] = sinf(radians);
  result.m[8] = -sinf(radians);
  result.m[10] = cosf(radians);
  return result;
}

inline Matix4x4 Matix4x4::RotateZ(float radians) {
  Matix4x4 result = result.Identity();
  result.m[0] = cosf(radians);
  result.m[1] = -sinf(radians);
  result.m[4] = sinf(radians);
  result.m[5] = cosf(radians);
  return result;
}

inline Matix4x4 Matix4x4::GetTransform(const Vector3& translate,
                const Vector3& scale,
                float rotateX, float rotateY,
                float rotateZ)   {

  Matix4x4 result = result.Identity();

  Matix4x4 translation;
  Matix4x4 scalation;
  Matix4x4 rotation;

  rotation = rotation.RotateX(rotateX).Multiply(rotation.RotateY(rotateY).Multiply(rotation.RotateZ(rotateZ)));
  result = translation.Translate(translate.x, translate.y, translate.z).Multiply(rotation.Multiply(scalation.Scale(scale.x, scale.y, scale.z)));

  return result;
}

inline Matix4x4 Matix4x4::GetTransform(float trans_x, float trans_y, float trans_z,
  float scale_x, float scale_y, float scale_z,
  float rotateX, float rotateY, float rotateZ)  {

  Matix4x4 result = result.Identity();

  Matix4x4 translation;
  Matix4x4 scalation;
  Matix4x4 rotation;

  rotation = rotation.RotateX(rotateX).Multiply(rotation.RotateY(rotateY).Multiply(rotation.RotateZ(rotateZ)));
  result = translation.Translate(trans_x, trans_y, trans_z).Multiply(rotation.Multiply(scalation.Scale(scale_x, scale_y, scale_z)));
  
  return result;
}

inline Vector4 Matix4x4::GetColum(int colum) const {
  return Vector4(m[colum], m[colum + 4], m[colum + 8], m[colum + 12]);
}

inline Vector4 Matix4x4::GetLine(int line) const {
  return Vector4(m[line * 4], m[line * 4 + 1], m[line * 4 + 2], m[line * 4 + 3]);
}

inline Matix4x4 Matix4x4::PerspectiveMatrix(float fov, float aspect,
  float near, float far) const {
  
  fov = 0.0f;
  aspect = 0.0f;
  near = 0.0f;
  far = 0.0f;

  return Matix4x4();
}

inline Matix4x4 Matix4x4::OrthoMatrix(float right, float left, float top, float bottom,
  float near, float far) const {

  right = 0.0f;
  left = 0.0f;
  top = 0.0f;
  bottom = 0.0f;
  near = 0.0f;
  far = 0.0f;

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
  for(int i = 0; i < 16; ++i) 
    if (m[i] != other.m[i]) 
      return false;
  return true;
}

inline bool Matix4x4::operator!=(const Matix4x4& other) {
  for(int i = 0; i < 16; ++i)
    if(m[i] == other.m[i])
      return false;
  return true;
}

inline void Matix4x4::operator=(const Matix4x4& other) {
  for(int i = 0; i < 16; ++i)
    this->m[i] = other.m[i];
  Matix4x4(*this);
}

#endif