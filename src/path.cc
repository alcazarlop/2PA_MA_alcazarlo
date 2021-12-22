
#include "path.h"

Path::Path(){
	position_ = {0.0f, 0.0f};
	rotation_ = 0.0f;
	scale_ = {0.0f, 0.0f};
	transform_ = Matrix3x3();
}

Path::Path(const Path& other){
	position_ = other.position_;
	rotation_ = other.rotation_;
	scale_ = other.scale_;	
	transform_ = other.transform_;

	points_ = other.points_;

}

Path::~Path(){
	points_.clear();
}

void Path::init(){
	Entity::init();
	
	position_ = {100.0f, 200.0f};
	rotation_ = 0.0f;
	scale_ = {10.0f, 10.0f};
	transform_ = Matrix3x3();

	points_.clear();

}

void Path::addPoints(const float& pos_x, const float& pos_y){
	Vector2 points(pos_x, pos_y);
	points_.push_back(points);
}

void Path::addPoints(const Vector2& vec){
	points_.push_back(vec);
}

void Path::draw(SDL_Renderer* render){

	if(enabled_){

		transform_ = transform_.Identity();
		transform_ = transform_.Multiply(Matrix3x3::Scale(scale_.x, scale_.y));
		transform_ = transform_.Multiply(Matrix3x3::Rotate(rotation_));
		transform_ = transform_.Multiply(Matrix3x3::Translate(position_.x, position_.y));

		std::vector<Vector2> transformed_points;

		for(uint32_t i = 0; i < points_.size(); ++i){
			Vector2 tmp = Matrix3x3::Mat3TransformVec2(transform_, points_[i]);
			transformed_points.push_back(tmp);
		}

		SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
		
		for(uint32_t i = 1; i < transformed_points.size(); ++i){
			SDL_RenderDrawLineF(render, transformed_points[i - 1].x, transformed_points[i - 1].y,
																	transformed_points[i].x, transformed_points[i].y);
		}
	}
}

void Path::cube(SDL_Renderer* render){

	Vector3 figure_points[8];

	figure_points[0] = {-1.0f, -1.0f, 1.0f};
	figure_points[1] = {1.0f, -1.0f, 1.0f};
	figure_points[2] = {1.0f, 1.0f, 1.0f};
	figure_points[3] = {-1.0f, 1.0f, 1.0f};
	figure_points[4] = {-1.0f, -1.0f, -1.0f};
	figure_points[5] = {1.0f, -1.0f, -1.0f};
	figure_points[6] = {1.0f, 1.0f, -1.0f};
	figure_points[7] = {-1.0f, 1.0f, -1.0f};

	if(enabled_){
		Matix4x4 m = m.Identity();
		m = m.Multiply(Matix4x4::Scale(50.0f, 50.0f, 50.0f));
		m = m.Multiply(Matix4x4::RotateX(0.0f));
		m = m.Multiply(Matix4x4::Translate(300.0f, 300.0f, 0.0f));

		m = m.Multiply(m.PerspectiveMatrix(10.0f, 10.0f, 0.1f, 50.0f));

		std::vector<Vector3> tr_points;
		Vector3 tmp;
		for(int i = 0; i < 8; ++i){
			tmp = Matix4x4::Mat4TransformVec3(m, figure_points[i]);
			tr_points.push_back(tmp);
		}

		SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);

		for(int i = 0; i < 4; ++i){
			SDL_RenderDrawLineF(render, tr_points[i].x, tr_points[i].y,
																	tr_points[(i + 1) % 4].x, tr_points[(i + 1) % 4].y);
			SDL_RenderDrawLineF(render, tr_points[i].x, tr_points[i].y,
																	tr_points[i + 4].x, tr_points[i + 4].y);
			SDL_RenderDrawLineF(render, tr_points[i + 4].x, tr_points[i + 4].y,
																	tr_points[((i + 1) + 4) % 4].x, tr_points[((i + 1) + 4) % 4].y);
		}

	}
}
