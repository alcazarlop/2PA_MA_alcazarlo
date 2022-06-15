///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Cube basic class header

#ifndef __CUBE_H__
#define __CUBE_H__ 1

#include <SDL.h>
#include "lib_math/vector3.h"
#include "lib_math/matrix4.h"

class Cube {

public:
	Cube();
	Cube(const Cube& other);
	virtual ~Cube();

	void init();
	void transform();
	void draw(SDL_Renderer* render);

	Vector3 position() const;
	Vector3 rotation() const;
	Vector3 scale() const;

	void set_position(const Vector3& pos);
	void set_rotation(const Vector3& rot);
	void set_scale(const Vector3& scale);

private:
	Vector3 position_;
	Vector3 scale_;
	Vector3 rotation_;

	Matix4x4 mat_;
	Vector3 points_[8];
};

#endif