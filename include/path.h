/// @author
/// @file

#ifndef __PATH_H__
#define __PATH_H__ 1

#include <vector>
#include "entity.h"

class Path : public Entity {

 public:
	Path();
	Path(const Path& other);
	virtual ~Path();

	void init();
	void addPoint(const Vector2& point);
	void draw() override;

 	uint8_t stroke_color_[4];
 	uint8_t fill_color_[4];
 	uint8_t solid_;

 protected:
 	std::vector<Vector2> points_;

};

#endif