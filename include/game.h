///@author Manuel Alcázar López <alcazarlo@esat-alumni.com>
///@file Basic game class header

#ifndef __GAME_H__
#define __GAME_H__ 1

#include <SDL.h>
#include <stdint.h>

#include "sdk_window.h"
#include "imgui_interface.h"
#include "sql_interface.h"
#include "ship.h"
#include "cube.h"
#include "sprite.h"

class Game {
	
 public:
 	Game();
 	Game(const Game& copy);
 	~Game();

 	void init();
 	void eventHandler();
 	void update();
 	void draw();
 	void end();

 	void run();

 private:

 	bool running_;

  Window display_;
  Ship ship_;
  Cube cube_;
  Sprite sprite_;
  Database database_;
};

#endif
