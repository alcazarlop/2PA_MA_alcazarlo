//@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
//@file Basic texture header class

#ifndef __TEXTURE_H__
#define __TEXTURE_H__ 1

#include <SDL.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "lib_math/vector4.h"

class Texture {
 
 public:

 	Texture();
 	Texture(const Texture& other);
 	~Texture();

 	void init(const char* p);
 	void init(int32_t width, int32_t height, uint8_t* pixels);

 	void release();

 	SDL_Rect getSprites(int32_t origin_x, int32_t origin_y,
 											int32_t width, int32_t height) const;

 	char* path;
 	SDL_Texture* texture_;
  SDL_Surface* surface_;
 	uint8_t is_procedural_;
  int32_t width_;
  int32_t height_;
  Vector4 color_;

};

#endif