
#include "Game.h""

using namespace sf;

const Time TIMEPERFRAME = seconds(1.f / 60.f);   // FRAME RATE OF OUR GAME ( 60 FPS )


GAME::GAME()
	:mWindow(VideoMode(800,600), "Simple Videogame"),
	mWorld(mWindow)
{
	
}


// MAIN LOOP
// WE CALL THE UPDATE FUNCTION EVERY FRAME USING FIXED TIME STEPS TECHNIQUE
// this way we ensure that if will run in the same way in every computer
// PROCESS ALL EVENTS -> UPDATE GAME LOGIC -> RENDER 
void GAME::run()
{
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;

	while (mWindow.isOpen())
	{
		Time elapsedTime = clock.restart();			// New Frame = Reset elapsedTime
		timeSinceLastUpdate += elapsedTime;			// Variable that holds the elapsed time since last update

		while (timeSinceLastUpdate > TIMEPERFRAME)
		{
			// Every time we are over the required amount of time for one frame 
			// We subtract the desired length of this frame and update the game

			timeSinceLastUpdate -= TIMEPERFRAME;
			processEvents();
			mWorld.update(TIMEPERFRAME);					// In world class we will update everything that we need

		}

		render();

	}

}


// Function for handle all types of events
void GAME::processEvents()
{
	sf::Event event;

	// Check if an event has triggered since last iteration of the loop
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:			// Close Window
					mWindow.close();
					break;
		}
	}
	
}

void GAME::update(sf::Time elapsedTime)
{
	mWorld.update(elapsedTime);
}

// FUNCTION TO RENDER OUR GAME TO SCREEN
void GAME::render()
{
	mWindow.clear();
	mWorld.draw();				//World class will handle the world render/draw

	// NOTHING TO DRAW FROM HERE

	mWindow.display();
}