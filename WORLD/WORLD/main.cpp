#include "Aircraft.h"

int main()
{	
	ResourceHolder < sf::Texture, Textures::ID > mTextures;
	mTextures.load(Textures::Raptor, "Media/Raptor.png");
	//Aircraft plane(Aircraft::Type Raptor, mTextures);

	sf::RenderWindow window(sf::VideoMode(640, 480), "World Drawing");

	while (window.isOpen())
	{
		// Check if user wants to close window
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}


		window.clear();
		window.display();
	}

	return 0;
}