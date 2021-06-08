#include "TextureHolder.h"



int main()
{	
	TextureHolder textures;
	textures.loadTexture(Textures::Airplane, "Media/Textures/Airplane.png"); // Load Airplane texture
	textures.loadTexture(Textures::Landscape, "Media/Textures/Desert.png"); // Load Dessert texture
	textures.loadTexture(Textures::Missile, "Media/Textures/Missile.png");	// Load Missile texture

	sf::Sprite playerPlane;
	playerPlane.setTexture(textures.get(Textures::Airplane));
	playerPlane.setPosition(100.f, 100.f);

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window with textures");

	while(window.isOpen())
	{
		// Check if user wants to close window
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}


		window.clear();
		window.draw(playerPlane);
		window.display();
	}


	return 0;
}

