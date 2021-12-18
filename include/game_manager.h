
#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include <SDL.h>
#include "sql_interface.h"
#include "imgui_interface.h"
#include "entity.h"
#include "path.h"

class GameManager{

 public:
 	static GameManager& instance(){
 		static GameManager* instance = new GameManager();
 		return *instance;
 	}

 	~GameManager();

 private:
 	GameManager();
 	GameManager(const GameManager& copy);

};

#endif