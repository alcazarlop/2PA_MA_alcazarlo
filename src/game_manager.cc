
#include "game_manager.h"

GameManager::GameManager(){
	title_ = "SQL Interface";
	screen_height_ = 600;
	screen_width_ = 600;
	window_ = nullptr;
	render_ = nullptr;
	info = nullptr;
	running_ = true;
}

GameManager::GameManager(const GameManager& copy){
	*this = copy;
}

GameManager::~GameManager(){

}

void GameManager::init(){
	SDL_Init(SDL_INIT_EVERYTHING);
	window_ = SDL_CreateWindow(title_,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
														 screen_width_, screen_height_, 0);
	render_ = SDL_CreateRenderer(window_, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	ImGuiInit(window_, render_);
}

void GameManager::handleEvent(){
	SDL_Event event;
	SDL_PollEvent(&event);
	ImGuiEvent(&event);

	if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE){
		running_ = false;
	}

}

void GameManager::update(){


}

void GameManager::draw(){

	ImGuiRenderInit(window_);

	SDL_SetRenderDrawColor(render_, 0x0, 0x0, 0x0, 0x0);
	SDL_RenderClear(render_);

	// ImGui::ShowDemoWindow();
	ImGuiShowData(&SQL, &info);

	ImGuiRenderClear();
	SDL_RenderPresent(render_);

}

void GameManager::end(){
	SDL_DestroyWindow(window_); window_ = nullptr;
	SDL_DestroyRenderer(render_); render_ = nullptr;
	ClearList(&info);
	ImGuiExit();
	SDL_Quit();
}

void GameManager::run(){

	init();

	while(running_){
		handleEvent();
		update();
		draw();
	}

}