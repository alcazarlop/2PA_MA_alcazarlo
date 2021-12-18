
// #include "texture.h"

// Texture::Texture(){
// 	texture_ = nullptr;
// 	surface_ = nullptr;
// 	is_procedural_ = 0;
// 	width_ = 0;
// 	height_ = 0;
// }

// Texture::Texture(const Texture& other){
// 	if(other.is_procedural_ == 0){
// 		strncpy(path, other.path, strlen(other.path));
// 		is_procedural_ = 0;
// 		texture_ = SDL_LoadBMP(path);
// 		if(texture_ == nullptr)
// 			printf("Error loading texture from file: %s\n",SDL_GetError());
// 	}
// 	else{
// 		if(strncmp(path, "", 2)){
// 			path = "";
// 			is_procedural_ = 1;
// 			width_ = other.width_;
// 			height_ = other.height_;
// 			color_.x = other.color_.x;
// 			color_.y = other.color_.y;
// 			color_.z = other.color_.z;
// 			color_.w = other.color_.w;
// 			surface_ = SDL_CreateRGBASurface(width_, height_, int32_t, color_.x, color_.y, color_.z, color_.w);
// 		}
// 	}
// }

// Texture::~Texture(){
// 	if(texture_ != nullptr)
// 		SDL_DestroyTexture(texture_);
// }

// void Texture::init(const char* p){

// 	release();

// 	if(p != nullptr){
// 		//load from file;
// 		//if(load == nullptr){
// 				//error
// 		// }
// 		// else{
// 			// is_procedural_ = 0;
// 		// }
// 	}

// }

// void Texture::init(int32_t width, int32_t height, uint8_t* pixels){

// 	release();

// 	if((pixels != nullptr) && (width > 0) && (height > 0)){
// 		// texture_ = load from memory
// 		if(texture_ == nullptr){
// 			//error
// 		}
// 		else {
// 			is_procedural_ = 1;
// 		}
// 	}

// }

// SDL_Rect Texture::getSprites(int32_t origin_x, int32_t origin_y,
// 														 int32_t width, int32_t height) const {


// 	if((origin_x >= 0) && (origin_x >= 0) && 
// 		(width >= 0) && (height >= 0)){

// 		SDL_Rect tmp = {origin_x, origin_y, width, height};


// 	}

// 	return tmp;

// }

// void Texture::release(){
// 	if(texture_ != nullptr)
// 		SDL_DestroyTexture(texture_);
// }