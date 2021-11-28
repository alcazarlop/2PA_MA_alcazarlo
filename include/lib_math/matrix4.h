#ifndef __MATRIX4_H__
#define __MATRIX4_H__ 1

#include "vector3.h"
#include "vector4.h"
#include "matrix3.h"

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

  Matix4x4 OrthoMatrix(float right, float left, float top, float valueottom,
	  float near, float far) const;

  Vector4 GetColum(int colum) const;
  Vector4 GetLine(int line) const;

  float m[16];

};

inline Matix4x4::Matix4x4() {
  for(int i = 0; i < 16; ++i)
    m[i];
}

inline Matix4x4::Matix4x4(float array[16]) {
  for(int i = 0; i < 16; ++i)
    m[i] = array[i];
}

inline Matix4x4::Matix4x4(float value) {
  for(int i = 0; i < 16; ++i)
    m[i] = value;
}

inline Matix4x4::Matix4x4(const Matix4x4& copy) {
  for(int i = 0; i < 16; ++i)
    m[i] = copy.m[i];
}

inline Matix4x4::~Matix4x4() {}

inline Matix4x4 Matix4x4::Identity() const {


  return Matix4x4();
}

inline Matix4x4 Matix4x4::Multiply(const Matix4x4& other) const {

  return Matix4x4();
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
    
  return Matix4x4();
}

inline Matix4x4 Matix4x4::Translate(const Vector3& distance){
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::Translate(float x, float y, float z){
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::Scale(const Vector3& scale){
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::Scale(float x, float y, float z){
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::RotateX(float radians){
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::RotateY(float radians){
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::RotateZ(float radians) {
  
  return Matix4x4();
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
  return Vector4(m[colum], m[colum + 4], m[colum + 8], m[colum + 12]);
}

inline Vector4 Matix4x4::GetLine(int line) const {
  return Vector4(m[line], m[line + 1], m[line + 2], m[line + 3]);
}

inline Matix4x4 Matix4x4::PerspectiveMatrix(float fov, float aspect,
  float near, float far) const {
  
  return Matix4x4();
}

inline Matix4x4 Matix4x4::OrthoMatrix(float right, float left, float top, float valueottom,
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
