
#include "ship.h"

Ship::Ship(){
	enabled_ = 1;
}

Ship::Ship(const Ship& other){
	enabled_ = other.enabled_;
}

Ship::~Ship(){
	
}

void Ship::init(){
	ship_points_[0] = {0.4f, 0.0f};
	ship_points_[1] = {0.1f, -0.3f};
	ship_points_[2] = {1.0f, -0.1f};
	ship_points_[3] = {-1.0f, -0.5f};
	ship_points_[4] = {0.4f, 0.0f};
	ship_points_[5] = {-1.0f, -1.2f};
	ship_points_[6] = {0.0f, 0.0f};
	ship_points_[7] = {-1.0f, 1.2f};
	ship_points_[8] = {0.4f, 0.0f};
	ship_points_[9] = {-1.0f, 0.5f};
	ship_points_[10] = {1.0f, 0.1f};
	ship_points_[11] = {0.1f, 0.3f};

	for(int i = 0; i < 12; ++i){
		addPoints(ship_points_[i]);
	}
}

