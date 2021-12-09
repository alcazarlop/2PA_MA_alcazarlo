
#include "path.h"

Path::Path(){
	position_ = {0.0f, 0.0f};
	rotation_ = 0.0f;
	scale_ = {0.0f, 0.0f};

	for(uint32_t i = 0; i < 4; ++i){
		stroke_color_[i] = 0xFF;
		fill_color_[i] = 0xFF;
	}

	solid_ = 0;
}

Path::Path(const Path& other){
	position_ = other.position_;
	rotation_ = other.rotation_;
	scale_ = other.scale_;

	for(uint32_t i = 0; i < 4; ++i){
		stroke_color_[i] = other.stroke_color_[i];
		fill_color_[i] = other.fill_color_[i];
	}

	solid_ = other.solid_;
	points_ = other.points_;
}

Path::~Path(){
	points_.clear();
}

void Path::init(){
	Entity::init();
	
	position_ = {0.0f, 0.0f};
	rotation_ = 0.0f;
	scale_ = {0.0f, 0.0f};

	for(uint32_t i = 0; i < 4; ++i){
		stroke_color_[i] = 0xFF;
		fill_color_[i] = 0xFF;
	}

	solid_ = 0;
	points_.clear();
}

void Path::addPoint(const Vector2& point){
	points_.push_back(point);
}

void Path::draw(){

	// if(enabled_){
	// 	Mat3 m = Translate(position_.x, position_.y);
	// 	m = Mat3Multiply(Mat3Scale(scale_.x, scale_.y), m);
	// 	m = Mat3Multiply(Mat3Rotate(rotation_), m);

	// 	std::vector<Vec2> transformed;

	// 	for(int i = 0; i < points_.size(); ++i){
	// 		Vec2 in = points_[i];
	// 		Vec2 aux;
	// 		Mat3TransformVec2(m, &in, &aux);
	// 		transformed.push_back(aux);
	// 	}

	// 	SetStrokeColor(stroke_color_[0], stroke_color_[1], 
	// 								 stroke_color_[2] ,stroke_color_[3]);

	// 	if(solid_ > 0){
	// 		SetFillColor(fill_color_[0], fill_color_[1], 
	// 								 fill_color_[3], fill_color_[3]);
	// 		DrawSolidPath((float*)transformed.data(), transformed.size(), true);
	// 	}
	// 	else{
	// 		DrawPath((float*) transformed.data(), transformed.size());
	// 	}


	// }


}
