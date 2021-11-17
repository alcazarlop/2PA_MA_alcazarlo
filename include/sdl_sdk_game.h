
#ifndef __SDL_SDK_GAME_H__
#define __SDL_SDK_GAME_H__ 1

#include <SDL.h>
#include "sdl_sdk_window.h"
#include "sql_interface.h"
#include "imgui_interface.h"

class Game{
	
	public:
		Game();
		~Game();

		void init();
		void handleEvent();
		void loop();
		void render();
		void gameExit();
		int run();

		bool running();

	private:
		bool isRunning;
		int flags;
		Window display;

		Database SQL;
		Info *info;

};

#endif // __SDL_SDK_GAME_H__