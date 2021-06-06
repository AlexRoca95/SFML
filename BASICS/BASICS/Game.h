#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class GAME
{
private:
	sf::RenderWindow myWindow;
	sf::Texture texture;
	sf::Sprite mPlayer;
	bool movingUp;
	bool movingDown;
	bool movingLeft;
	bool movingRight;

	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	void handleUserInput(sf::Keyboard::Key, bool);

public:
	GAME();					// Constructor
	void run();				// Function that handles our main loop

};




#endif
