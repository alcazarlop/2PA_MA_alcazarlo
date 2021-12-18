
#include "sdk_window.h"

Window::Window(){
	window_ = nullptr;
	render_ = nullptr;
}

Window::Window(const Window& copy){
	window_ = copy.window_;
	render_ = copy.render_;
}

Window::~Window(){}

void Window::init(char* title, uint32_t width, uint32_t height){

	window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
														 width, height, 0);

	if(nullptr == window_) {
		printf("Error creating a new window: %s\n", SDL_GetError());
		return;
	}

	render_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(nullptr == render_){
		printf("Error creating a new renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window_);
		return;
	}

}

void Window::end(){
	SDL_DestroyRenderer(render_);
	SDL_DestroyWindow(window_);
}

SDL_Renderer* Window::render(){
	return render_;
}

SDL_Window* Window::window(){
	return window_;
}