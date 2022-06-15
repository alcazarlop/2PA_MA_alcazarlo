///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Sprite basic class header

#ifndef __SPRITE_H__
#define __SPRITE_H__ 1

#include <SDL.h>
#include "..\deps\sdl2_image\include\SDL_image.h"
#include "entity.h"

class Sprite : public Entity {

 public:
 	Sprite();
 	Sprite(const Sprite& copy);
 	virtual ~Sprite();

 	SDL_Texture* loadFromFile(const char* path, SDL_Renderer* render);
 	void draw(SDL_Renderer* render) override;
  void release();

 private:
 	SDL_Texture* tex_;

};

#endif // __SPRITE_H__