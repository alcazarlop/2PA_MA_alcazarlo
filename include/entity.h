//@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
//@file Entity basic class header

#ifndef __ENTITY_H__
#define __ENTITY_H__ 1

#include <SDL.h>
#include "lib_math/vector2.h"
#include <stdint.h>

class Entity {

 public:
 	Entity();
 	Entity(int32_t tag, uint8_t enabled);
 	Entity(const Entity& copy);

 	virtual ~Entity();

 	virtual void init();
 	virtual  void init(int32_t tag, uint8_t enabled);

 	virtual void set_position(const Vector2& pos);
 	virtual void set_rotation(const float rot);
 	virtual void set_scale(const Vector2& scale);

 	virtual Vector2 position() const;
 	virtual float rotation() const;
 	virtual Vector2 scale() const;

 	virtual void draw(SDL_Renderer* render) = 0;

 	int32_t tag_;
 	uint8_t enabled_;

 protected:
 	Vector2 position_;
 	float rotation_;
 	Vector2 scale_;

};

#endif // __ENTITY_H__