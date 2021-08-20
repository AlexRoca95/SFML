#ifndef GAME_H
#define GAME_H

#include "World.h"

class GAME : sf::NonCopyable
{
private:

	sf::RenderWindow mWindow;
	World mWorld;

	void processEvents();
	void update(sf::Time);
	void render();

public:

	GAME();
	void run();				// Main loop 



};


#endif // !"GAME_H"
