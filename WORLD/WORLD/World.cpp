

#include "World.h"


// Initialize and build up our World
World::World(sf::RenderWindow& window)
	:mWindow(window),
	mWorldView(window.getDefaultView()),
	mWorldBounds(										// World Bounding Boxes
		0.f,											// Left X position
		0.f,											// Top Y position  ( Upper left corner position (0,0) )
		mWorldView.getSize().x,							// Width
		2000.f),										// Height (arbitrary value)
	mSpawnPosition(
		mWorldView.getSize().x / 2.f,							// X
		mWorldBounds.height - mWorldView.getSize().y / 2.f),	// Y
	mPlayerAircraft(nullptr),
	mScrollSpeed(-50.f)
{
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);

}


void World::update(sf::Time dt)
{

}

void World::draw()
{

}

// Load all textures of our World
void World::loadTextures()
{
	mTextures.load(Textures::Desert, "Media/Desert.png");
	mTextures.load(Textures::Eagle, "Media/Eagle.png");
	mTextures.load(Textures::Raptor, "Media/Raptor.png");
}

void World::buildScene()
{

}