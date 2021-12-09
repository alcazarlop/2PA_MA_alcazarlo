//@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
//@file Basic sprite header class


#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

// #include <SDL_image.h>
#include <stdint.h>
#include "entity.h"
#include "texture.h"

class Sprite : public Entity {
 
 public:
 	Sprite(Texture* tex, 
 		int32_t origin_x, int32_t origin_y
 		int32_t width, int32_t height);
 	Sprite(const Sprite& o);
 	virtual ~Sprite();

 	void size(int32_t* width, int32_t* height) const;
 	void getPixel(int32_t x, int32_t y, uint8_t color[4]) const;
 	void draw() override;

 protected:
 	SDL_Texture sprite_;

};

#endif //__SPRITE_H__