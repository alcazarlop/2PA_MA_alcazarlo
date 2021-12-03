
#include "entity.h"

Entity::Entity(){
	tag_ = 0;
	enabled_ = 1;
}

Entity::entity(int32_t tag, uint8_t enabled){
	tag_ = tag;
	enabled_ = enabled_;
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

void Entity::set_poisition(const Vector2 pos) const {
	position_ = pos;
}

void Entity::set_rotation(const float rot) const {
	rotation_ = rot;
}

void Entity::set_scale(const Vector2 scale) const {
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

