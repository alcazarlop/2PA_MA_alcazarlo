
#include <SDL.h>
#include "game_manager.h"

int main(int argc, char* argv[]){

	argc = 0;
	argv = nullptr;

	GameManager::instance().run();

	return 0;

}
