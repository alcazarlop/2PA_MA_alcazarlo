///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Path basic class header

#ifndef __PATH_H__
#define __PATH_H__ 1

#include <vector>
#include "entity.h"
#include "lib_math/matrix3.h"

class Path : public Entity {

 public:
	Path();
	Path(const Path& other);
	virtual ~Path();

	void init();
	void addPoints(const float& pos_x, const float& pos_y);
	void addPoints(const Vector2& vec);

	void draw(SDL_Renderer* render) override;

protected:
	std::vector<Vector2> points_;
	Matrix3x3 transform_;


};

#endif