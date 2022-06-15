#include "cube.h"

Cube::Cube(){
	position_ = Vector3();
	rotation_ = Vector3();
	scale_ = Vector3();
	mat_ = Matix4x4();
}

Cube::Cube(const Cube& other){
	position_ = other.position_;
	rotation_ = other.rotation_;
	scale_ = other.scale_;
}

Cube::~Cube(){

}

void Cube::init(){
	points_[0] = {-1.0f, -1.0f, 1.0f};
	points_[1] = {1.0f, -1.0f, 1.0f};
	points_[2] = {1.0f, 1.0f, 1.0f};
	points_[3] = {-1.0f, 1.0f, 1.0f};
	points_[4] = {-1.0f, -1.0f, -1.0f};
	points_[5] = {1.0f, -1.0f, -1.0f};
	points_[6] = {1.0f, 1.0f, -1.0f};
	points_[7] = {-1.0f, 1.0f, -1.0f};
}

void Cube::transform(){
	mat_ = mat_.Identity();
	mat_ = Matix4x4::Translate(position_.x, position_.y, 0.0f).Multiply(mat_);
	mat_ = Matix4x4::Scale(scale_.x, scale_.y, scale_.z).Multiply(mat_);
	mat_ = Matix4x4::ProjectionMatrix().Multiply(mat_);
	mat_ = Matix4x4::Translate(0.0f, 0.0f, position_.z).Multiply(mat_);
	mat_ = Matix4x4::RotateX(rotation_.x).Multiply(mat_);
	mat_ = Matix4x4::RotateY(rotation_.y).Multiply(mat_);
	mat_ = Matix4x4::RotateZ(rotation_.z).Multiply(mat_);
}

void Cube::draw(SDL_Renderer* render){
	transform();
	Vector3 tr_points[8];

	for(int i = 0; i < 8; ++i){
		 tr_points[i] = mat_.Mat4TransformVec3(points_[i]);
	}

	SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

	for(int i = 0; i < 4; ++i){
		SDL_RenderDrawLineF(render, tr_points[i].x, tr_points[i].y,
																tr_points[(i + 1) % 4].x, tr_points[(i + 1) % 4].y);
		SDL_RenderDrawLineF(render, tr_points[i].x, tr_points[i].y,
																tr_points[(i + 4)].x, tr_points[(i + 4)].y);
		SDL_RenderDrawLineF(render, tr_points[(i + 4)].x, tr_points[(i + 4)].y,
																tr_points[((i + 1) % 4) + 4].x, tr_points[((i + 1) % 4) + 4].y);
	}
}

Vector3 Cube::position() const {
	return position_;
}

Vector3 Cube::rotation() const {
	return rotation_;
}

Vector3 Cube::scale() const {
	return scale_;
}

void Cube::set_position(const Vector3& pos){
	position_ = pos;
}

void Cube::set_rotation(const Vector3& rot){
	rotation_ = rot;
}

void Cube::set_scale(const Vector3& scale){
	scale_ = scale;
}