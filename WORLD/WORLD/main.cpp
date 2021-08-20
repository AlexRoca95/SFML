#include "Game.h"
#include <iostream>

int main()
{	

	try {
			GAME game;
			game.run();				// Run our GAME
	}
	catch(std::exception& e){		// NEED TO HANDLE EXCEPTIONS TO AVOID PROGRAM TO CRASH

		std::cout << "\nEXCEPTION" << e.what() << std::endl;
	}


	return 0;
}