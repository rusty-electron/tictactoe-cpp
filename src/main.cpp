#include <iostream>
#include "Game.h"
#include <string>

// initialize game count
int Game::_gamecount = 0;

int main(int argc, char *argv[])
{
	bool two_player = false;
	if (argc > 1 && (std::string(argv[1]) == "-m" || std::string(argv[1]) == "--multi")) {
		two_player = true;
	}
	Game gm = Game(3, two_player);
	gm.run();
}