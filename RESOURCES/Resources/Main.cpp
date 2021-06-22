#include "ResourceHolder.h"



int main()
{	
	ResourceHolder<sf::Texture, Textures::ID> textures;
	textures.load(Textures::Airplane, "Media/Textures/Airplane.png"); // Load Airplane texture
	textures.load(Textures::Landscape, "Media/Textures/Desert.png"); // Load Dessert texture
	textures.load(Textures::Missile, "Media/Textures/Missile.png");	// Load Missile texture
	
	sf::Sprite playerPlane;
	sf::Sprite landScape;
	playerPlane.setTexture(textures.get(Textures::Airplane));
	landScape.setTexture(textures.get(Textures::Landscape));
	playerPlane.setPosition(100.f, 100.f);
	
	sf::RenderWindow window(sf::VideoMode(640, 480), "My window with textures");

	
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
		window.draw(landScape);
		window.draw(playerPlane);
		window.display();
	}
	

	return 0;
}

