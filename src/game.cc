
#include "game.h"

Game::Game(){
	running_ = true;
	info_ = nullptr;
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

	path_.init();
	
	Vector2 playerPoints[12];

	playerPoints[0] = {0.4f, 0.0f};
	playerPoints[1] = {0.1f, -0.3f};
	playerPoints[2] = {1.0f, -0.1f};
	playerPoints[3] = {-1.0f, -0.5f};
	playerPoints[4] = {0.4f, 0.0f};
	playerPoints[5] = {-1.0f, -1.2f};
	playerPoints[6] = {0.0f, 0.0f};

	playerPoints[7] = {-1.0f, 1.2f};
	playerPoints[8] = {0.4f, 0.0f};
	playerPoints[9] = {-1.0f, 0.5f};
	playerPoints[10] = {1.0f, 0.1f};
	playerPoints[11] = {0.1f, 0.3f};

	for(int i = 0; i < 12; ++i){
		path_.addPoints(playerPoints[i]);
	}

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
	ImGuiVectorCalculator();
	ImGuiShowData(&database_, &info_);

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

	end();

}

void Game::end(){

	ClearList(&info_);
	ImGuiExit();
	display_.end();
	SDL_Quit();
}
