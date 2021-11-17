
#include "sdl_sdk_game.h"
#include <stdio.h>

Game::Game()
{
	isRunning = false;
	flags = 0;
}

Game::~Game()
{

}

void Game::init()
{
	info = nullptr;
	SDL_Init(SDL_INIT_EVERYTHING);
	display.init();
	isRunning = true;
	ImGuiInit(display.getWindow(), display.getRender());

}

void Game::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
	ImGuiEvent(&event);
}

void Game::loop()
{

}

void Game::render()
{

	ImGuiRenderInit(display.getWindow());

	SDL_SetRenderDrawColor(display.getRender(), 0x0, 0x0, 0x0, 0x0);
	SDL_RenderClear(display.getRender());

	// ImGui::ShowDemoWindow();
	ImGuiShowData(&SQL, &info);

	ImGuiRenderClear();
	SDL_RenderPresent(display.getRender());

}

void Game::gameExit()
{
	ClearList(&info);
	ImGuiExit();
	SDL_Quit();
}

int Game::run()
{

	init();

	while(running())
	{
		handleEvent();
		loop();
		render();
	}

	gameExit();

	return 0;
}

bool Game::running()
{
	return isRunning;
}

