
#include "sprite.h"

Sprite::Sprite(){
	tex_ = nullptr;
}

Sprite::Sprite(const Sprite& copy){
	tex_ = copy.tex_;
}

Sprite::~Sprite(){}

SDL_Texture* Sprite::loadFromFile(char* path, SDL_Renderer* render){

	if(nullptr != tex_){
		SDL_DestroyTexture(tex_);
	}

	Entity::init();

	SDL_Surface* texture = IMG_Load(path);
	SDL_Texture* optimizedTexture = SDL_CreateTextureFromSurface(render, texture);
	
	scale_.x = (float) texture->w;
	scale_.y = (float) texture->h;

	SDL_FreeSurface(texture);

	tex_ = optimizedTexture;
	return tex_;

}

void Sprite::draw(SDL_Renderer* render) {
	if(enabled_){
		SDL_FRect dstRect = {position_.x, position_.y, scale_.x, scale_.y};
		SDL_RenderCopyExF(render, tex_, nullptr, &dstRect, rotation_, nullptr, SDL_FLIP_NONE);
	}
}

void Sprite::release(){
	SDL_DestroyTexture(tex_);
}