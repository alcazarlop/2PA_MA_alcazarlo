///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Window basic class header

#ifndef __SDK_WINDOW_H__
#define __SDK_WINDOW_H__ 1

#include <SDL.h>
#include <stdint.h>
#include <stdio.h>

class Window {
	
public: 
	Window();
	Window(const Window& copy);
	~Window();

	void init(char* title, uint32_t width, uint32_t height);
	void end();

	SDL_Renderer* render();
	SDL_Window* window();

private:

	SDL_Window* window_;
	SDL_Renderer* render_;

};

#endif