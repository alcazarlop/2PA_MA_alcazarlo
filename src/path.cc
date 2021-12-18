
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

void Path::draw(SDL_Renderer* render){

	if(enabled_){
		Matrix3x3 transform_matrix = transform_matrix.Identity();
		Matrix3x3 translate = translate.Multiply(Matrix3x3::Translate(position_.x, position_.y));
		Matrix3x3 scale = scale.Multiply(Matrix3x3::Scale(scale_.x, scale_.y));
		Matrix3x3 rotate = rotate.Multiply(Matrix3x3::Rotate(rotation_));
		transform_matrix.Multiply(translate.Multiply(scale.Multiply(rotate)));

		std::vector<Vector2> transformed_points;

		for(uint32_t i = 0; i < points_.size(); ++i){
			transformed_points.push_back(Matrix3x3::Mat3TransformVec2(transform_matrix, points_[i]));
		}

		for(uint32_t i = 1; i < points_.size(); ++i){
			SDL_RenderDrawLineF(render, transformed_points[i - 1].x, transformed_points[i - 1].y, 
													 transformed_points[i].x, transformed_points[i].y);
		}

	}


}
