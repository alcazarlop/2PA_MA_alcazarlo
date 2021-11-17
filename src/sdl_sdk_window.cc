
#include "sdl_sdk_window.h"

Window::Window()
{
	window = NULL;
	renderer = NULL;
	title = "SQL Interface";
	width = 800;
	height = 600;
}

Window::~Window()
{
	SDL_DestroyWindow(window); window = NULL;
	SDL_DestroyRenderer(renderer); renderer = NULL;
}

void Window::init()
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0x0);
}

SDL_Window* Window::getWindow()
{
	return window;
}

SDL_Renderer* Window::getRender()
{
	return renderer;
}