
#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include <SDL.h>
#include "sql_interface.h"
#include "imgui_interface.h"

class GameManager{

 public:
 	static GameManager& instance(){
 		static GameManager* instance = new GameManager();
 		return *instance;
 	}

 	~GameManager();

 	void init();
 	void handleEvent();
 	void update();
 	void draw();
 	void end();

 	void run();

 	SDL_Window* widnow();
 	SDL_Renderer* render();

 protected:
 	SDL_Window* window_;
 	SDL_Renderer* render_;
 	int screen_height_;
 	int screen_width_;

 private:
 	GameManager();
 	GameManager(const GameManager& copy);

 	char* title_;
 	bool running_;
 	
 	Database SQL;
 	Info *info;

};

#endif