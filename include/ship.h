///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Ship basic class header

#ifndef __SHIP_H__
#define __SHIP_H__ 1

#include "path.h"

class Ship : public Path {

 public:
	Ship();
	Ship(const Ship& other);
	virtual ~Ship();

	void init();

protected:
	Vector2 ship_points_[12];

};

#endif