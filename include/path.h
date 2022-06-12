///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Path basic class header

#ifndef __PATH_H__
#define __PATH_H__ 1

#include <vector>
#include "entity.h"
#include "lib_math/vector2.h"
#include "lib_math/vector3.h"
#include "lib_math/matrix3.h"
#include "lib_math/matrix4.h"

class Path : public Entity {

 public:
	Path();
	Path(const Path& other);
	virtual ~Path();

	void init();
	void addPoints(const float& pos_x, const float& pos_y);
	void addPoints(const Vector2& vec);

	void draw(SDL_Renderer* render) override;
	void cube(SDL_Renderer* render);

	Vector3 cubePosition() const;
	Vector3 cubeScalation() const;
	Vector3 cubeRotation() const;

	void setCubePosition(const Vector3& pos);
	void setCubeScalation(const Vector3& scale);
	void setCubeRotation(const Vector3& angle);

protected:
	std::vector<Vector2> points_;
	Matrix3x3 transform_;

	Vector3 cube_position_;
	Vector3 cube_scale_;
	Vector3 cube_rotation_;

};

#endif