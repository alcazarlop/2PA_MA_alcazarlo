
#include "game.h"

Game::Game(){
	running_ = true;
}

Game::Game(const Game& copy){
	running_ = copy.running_;
	display_ = copy.display_;
}

Game::~Game(){}

void Game::init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	display_.init("Demo", 800, 600);


	ImGuiInit(display_.window(), display_.render());
}

void Game::eventHandler(){
	SDL_Event event;
	SDL_PollEvent(&event);
	ImGuiEvent(&event);

	if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
		running_ = false;
	}
}

void Game::update(){

}

void Game::draw(){
	ImGuiRenderInit(display_.window());
	SDL_SetRenderDrawColor(display_.render(), 0x0, 0x0, 0x0, 0x0);
	SDL_RenderClear(display_.render());

	ImGuiMatrixCalculator();

	ImGuiRenderClear();
	SDL_RenderPresent(display_.render());
}

void Game::run(){

	init();

	while(running_){
		eventHandler();
		update();
		draw();
	}

}

void Game::end(){

	ImGuiExit();
	display_.end();
	SDL_Quit();
}





