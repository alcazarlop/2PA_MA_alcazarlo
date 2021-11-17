
#ifndef __SDL_SDK_WINDOW_H__
#define __SDL_SDK_WINDOW_H__ 1

#include <SDL.h>

class Window{

	public:
		Window();
		~Window();

		void init();

		SDL_Window* getWindow();
		SDL_Renderer* getRender();

	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		
		int width;
		int height;
		const char* title;

};

#endif