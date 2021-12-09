
#include "texture.h"

Texture::Texture(){

	pixels_buffer_ = nullptr;
	texture_ = nullptr;
	is_procedural_ = 0;

}

Texture::Texture(const Texture& other){

	if(other.is_procedural_ == 0){
		strncpy(path, other.path, strlen(other.path));
		pixels_buffer_ = nullptr;
		is_procedural_ = 0;
	}
	else{
		if(strncmp(path, "", 2)){
			// texture_ = sprite from file (path)
			// path = "";
			// is_procedural_ = 1;
			// pixels_buffer_ = o.pixels_buffer_;
			if(pixels_buffer_ != nullptr){
				// int32_t w, h;
				// o.size(&w, &h);
				// texture_ = sprite from memroy (w, h, pixels_buffer_);
			}
		}
	}

}

Texture::~Texture(){
	if(texture_ != nullptr)
		SDL_DestroyTexture(texture_);
}

void Texture::init(const char* p){

	release();

	if(p != nullptr){
		//load from file;
		//if(load == nullptr){
				//error
		// }
		// else{
			// is_procedural_ = 0;
		// }
	}

}

void Texture::init(int32_t width, int32_t height, uint8_t* pixels){

	release();

	if((pixels != nullptr) && (width > 0) && (height > 0)){
		// texture_ = load from memory
		if(texture_ == nullptr){
			//error
		}
		else {
			is_procedural_ = 1;
			pixels_buffer_ = pixels;
		}
	}

}

void Texture::size(int32_t* widht, int32_t* height) const {

	if((width != nullptr) && (height != nullptr)){
		// width = algo
		//height = algo
	}

}

SDL_Rect Texture::getSprites(int32_t origin_x, int32_t origin_y,
														 int32_t width, int32_t height) const {


	if((origin_x >= 0) && (origin_x >= 0) && 
		(width >= 0) && (height >= 0)){

		SDL_Rect tmp = {origin_x, origin_y, width, height};


	}

	return tmp;

}

void Texture::release(){
	if(texture_ != nullptr)
		SDL_DestroyTexture(texture_);
}