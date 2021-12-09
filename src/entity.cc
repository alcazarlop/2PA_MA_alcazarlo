
#include "entity.h"

Entity::Entity(){
	tag_ = 0;
	enabled_ = 1;
}

Entity::Entity(int32_t tag, uint8_t enabled){
	tag_ = tag;
	enabled_ = enabled;
}

Entity::~Entity(){}

void Entity::init(){
	tag_ = 0;
	enabled_ = 1;
}

void Entity::init(int32_t tag, uint8_t enabled){
	tag_ = tag;
	enabled_ = enabled;
}

void Entity::set_position(const Vector2& pos) {
	position_ = pos;
}

void Entity::set_rotation(const float rot) {
	rotation_ = rot;
}

void Entity::set_scale(const Vector2& scale) {
	scale_ = scale;
}

Vector2 Entity::position() const {
	return position_;
}

float Entity::rotation() const {
	return rotation_;
}

Vector2 Entity::scale() const {
	return scale_;
}

