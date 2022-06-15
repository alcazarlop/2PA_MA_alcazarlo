
#include "path.h"

Path::Path(){
	enabled_ = 1;
}

Path::Path(const Path& other){
	position_ = other.position_;
	rotation_ = other.rotation_;
	scale_ = other.scale_;	
}

Path::~Path(){
	points_.clear();
}

void Path::init(){
	Entity::init();

	points_.clear();
}

void Path::addPoints(const float& pos_x, const float& pos_y){
	points_.push_back(Vector2(pos_x, pos_y));
}

void Path::addPoints(const Vector2& vec){
	points_.push_back(vec);
}

void Path::draw(SDL_Renderer* render){

	if(enabled_){

		transform_ = transform_.Identity();
		transform_ = transform_.Scale(scale_.x, scale_.y).Multiply(transform_);
		transform_ = transform_.Rotate(rotation_).Multiply(transform_);
		transform_ = transform_.Translate(position_.x, position_.y).Multiply(transform_);

		std::vector<Vector2> transformed_points;

		for(uint32_t i = 0; i < points_.size(); ++i){
			Vector2 tmp = transform_.Mat3TransformVec2(points_[i]);
			transformed_points.push_back(tmp);
		}

		SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
		
		for(uint32_t i = 1; i < transformed_points.size(); ++i){
			SDL_RenderDrawLineF(render, transformed_points[i - 1].x, transformed_points[i - 1].y,
																	transformed_points[i].x, transformed_points[i].y);
		}
	}
}
