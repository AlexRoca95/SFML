#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

using namespace sf;

int main()
{	
	// Create a window with size and add a text
	RenderWindow window(VideoMode(200, 200), "SFML PORTABLE WORKS!");

	// Draw a shape into the window and fill it
	CircleShape shape(100.f);
	shape.setFillColor(Color::Blue);


	while (window.isOpen())
	{
		// Check if user wants to close window
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}


		window.clear();
		window.draw(shape);
		window.display();

	}


	return 0;
}