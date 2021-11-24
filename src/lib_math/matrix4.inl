 
 #include "matrix4.h"


inline Matix4x4::Matix4x4() {

}

inline Matix4x4::Matix4x4(float array[16]) {
}

inline Matix4x4::Matix4x4(float value) {
	
}

inline Matix4x4::Matix4x4(const Matix4x4& copy) {
	
}

inline Matix4x4::~Matix4x4() {

}

inline Matix4x4 Matix4x4::Identity() const {
	return Matix4x4();
}

inline Matix4x4 Matix4x4::Multiply(const Matix4x4& other)const  {
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

	Matrix4x4 result;
	Matrix4x4 translation;
	Matrix4x4 scalation;
	Matrix4x4 rotation;

	rotation = rotation.RotateX(rotateX).Multiply(rotation.RotateY(rotateY).Multiply(rotation.RotateZ(rotateZ)));
	result = translation.Translate(trans_x, trans_y, trans_z).Multiply(rotation.Multiply(scalation.Scale(scale_x, scale_y, scale_z)));
	
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

inline Matix4x4 Matix4x4::OrthoMatrix(float right, float left, float top, float valueottom,
	float near, float far) const {

	return Matix4x4();
}



inline Matix4x4 Matix4x4::operator+(const Matix4x4& other) const {
	return Matix4x4();
}

inline Matix4x4& Matix4x4::operator+=(const Matix4x4& other) {
	
}

inline Matix4x4 Matix4x4::operator+(float value) const {
	return Matix4x4();
}

inline Matix4x4& Matix4x4::operator+=(float value) {	
}


inline Matix4x4 Matix4x4::operator-(const Matix4x4& other) const  {
	return Matix4x4();
}

inline Matix4x4& Matix4x4::operator-=(const Matix4x4& other) {
}

inline Matix4x4 Matix4x4::operator-(float value) const  {
	return Matix4x4();
}

inline Matix4x4& Matix4x4::operator-=(float value) {
}

inline Matix4x4& Matix4x4::operator*=(float value) {
}

inline Matix4x4 Matix4x4::operator*(float value) const  {
	return Matix4x4();
}

inline Matix4x4& Matix4x4::operator/=(float value) {
	
}

inline Matix4x4 Matix4x4::operator/(float value) const {
	return Matix4x4();
}

inline bool Matix4x4::operator==(const Matix4x4& other) {
	return true;
}

inline bool Matix4x4::operator!=(const Matix4x4& other) {
	return false;
}

inline void Matix4x4::operator=(const Matix4x4& other) {
}
