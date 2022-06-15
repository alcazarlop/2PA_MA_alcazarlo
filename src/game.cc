
#include "game.h"

Game::Game(){
	running_ = true;
}

Game::Game(const Game& copy){
	running_ = copy.running_;
	display_ = copy.display_;
	ship_ = copy.ship_;
	cube_ = copy.cube_;
	sprite_ = copy.sprite_;
	database_ = copy.database_;
}

Game::~Game(){}

void Game::init(){
	SDL_Init(SDL_INIT_EVERYTHING);

	SQLInit(&database_, "../data/Game.db");
	display_.init("Demo", 800, 600);
	ImGuiInit(display_.window(), display_.render());

	ship_.init();
	ship_.set_position(Vector2(100.0f, 100.0f));
	ship_.set_scale(Vector2(10.0f, 10.0f));
	ship_.set_rotation(0.0f);

	cube_.init();
	cube_.set_position(Vector3(200.0f, 200.0f, 5.0f));
	cube_.set_scale(Vector3(200.0f, 200.0f, 1.0f));
	cube_.set_rotation(Vector3(0.0f, 0.0f, 0.0f));

	sprite_.loadFromFile("../data/melocoton.png", display_.render());
	sprite_.set_position(Vector2(400.0f, 300.0f));
	sprite_.set_scale(Vector2(100.0f, 100.0f));

}

void Game::eventHandler(){
	SDL_Event event;
	SDL_PollEvent(&event);
	ImGuiEvent(&event);
	if(event.type == SDL_QUIT){
		running_ = false;
	}
}

void Game::update(){


}

void Game::draw(){
	ImGuiRenderInit(display_.window());
	SDL_SetRenderDrawColor(display_.render(), 0x0, 0x0, 0x0, 0x0);
	SDL_RenderClear(display_.render());

	// ImGuiMatrixCalculator();
	// ImGuiVectorCalculator();
	// ImGui::SetNextWindowPos(ImVec2(200.0f, 200.0f));
	ImGuiShowData(&database_);

	ship_.draw(display_.render());
	// cube_.draw(display_.render());
	// ImGui3DTransform(cube_);
	ImGui2DTransform(ship_);

	// sprite_.draw(display_.render());

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

	// ClearList(&info_);
	SQLExit(&database_);
	ImGuiExit();
	display_.end();
	SDL_Quit();
}
