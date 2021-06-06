#include "Game.h"
#include <iostream>

using namespace sf;

const float PLAYERSPEED = 100.0f;
const Time TIMEPERFRAME = seconds(1.f / 60.f);   // FRAME RATE OF OUR GAME ( 60 FPS )

// CONSTRUCTOR 
GAME::GAME():myWindow(VideoMode(800,600), "My Videogame"), mPlayer()
{	

	// LOADING TEXTURE
	if (!texture.loadFromFile("resources/dragon.png"))
	{
		std::cout << "Error Loading file" << std::endl;
	}
	
	mPlayer.setTexture(texture);
	mPlayer.setPosition(100.f, 100.f);

	movingDown = movingLeft = movingRight = movingUp = false;

	

}

// MAIN LOOP
// WE CALL THE UPDATE FUNCTION EVERY FRAME USING FIXED TIME STEPS TECHNIQUE
// this way we ensure that if will run in the same way in every computer
// PROCESS ALL EVENTS -> UPDATE GAME LOGIC -> RENDER 
void GAME::run()
{

	Clock clock;	// SFML CLOCK
	Time timeSinceLastUpdate = Time::Zero;
	while (myWindow.isOpen())
	{
		// Every frame we reset the clock and the elapsed time to zero
		Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;			// Variable that holds the elapsed time since last update

		while(timeSinceLastUpdate > TIMEPERFRAME)
		{	
			// Every time we are over the required amount of time for one frame 
			// We subtract the desired length of this frame and update the game
			timeSinceLastUpdate -= TIMEPERFRAME;
			processEvents();
			update(TIMEPERFRAME);
			
		}

		render();
	}
}

// FUNCTION FOR HANDLE ALL EVENTS
void GAME::processEvents()
{
	Event event;

	// Check if an event has triggered since last iteration of the loop
	while (myWindow.pollEvent(event))
	{	
		switch (event.type)
		{
		case Event::KeyPressed:		// User press a key
			handleUserInput(event.key.code, true);
			break;

		case Event::KeyReleased:	// User release a key
			handleUserInput(event.key.code, false);
			break;

		case Event::Closed:		// Close Window
			myWindow.close();
			break;
		}
		

	}

}

// FUNCTION TO UPDATE THE GAME LOGIC
void GAME::update(Time deltaTime)
{
	// INDEPENDENT FRAME MOVEMENT
	Vector2f movement(0.0f, 0.0f);		// SFML vector
	if (movingUp)
		movement.y -= PLAYERSPEED;
	if (movingDown)
		movement.y += PLAYERSPEED;
	if (movingLeft)
		movement.x -= PLAYERSPEED;
	if (movingRight)
		movement.x += PLAYERSPEED;


	// DISTANCE = SPEED * TIME 
	mPlayer.move(movement * deltaTime.asSeconds());

}

// FUNCTION TO RENDER OUR GAME TO SCREEN
void GAME::render()
{
	// WE clear the windows with a black color
	myWindow.clear(Color::Black);

	// We draw everything that we want
	myWindow.draw(mPlayer);

	// Display everything on the screen
	myWindow.display();


}

// Function that checks if a key is pressed or not (and determines which one is pressed)
void GAME::handleUserInput(Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case Keyboard::W:  // UP
		movingUp = isPressed;
		break;
	case Keyboard::S:	// DOWN
		movingDown = isPressed;
		break;
	case Keyboard::A:	// LEFT
		movingLeft = isPressed;
		break;
	case Keyboard::D:	// RIGHT
		movingRight = isPressed;
		break;
	}

}