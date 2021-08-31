

#include "World.h"
#include "SpriteNode.h"


// Initialize and build up our World
World::World(sf::RenderWindow& window)
	:mWindow(window),
	mWorldView(window.getDefaultView()),
	mWorldBounds(										// World Bounding Boxes
		0.f,											// Left X position
		0.f,											// Top Y position  ( Upper left corner position (0,0) )
		mWorldView.getSize().x,							// Width
		20000.f),										// Height (arbitrary value)
	mSpawnPosition(
		mWorldView.getSize().x / 2.f,							// X
		mWorldBounds.height - mWorldView.getSize().y / 2.f),	// Y
	mPlayerAircraft(nullptr),
	mScrollSpeed(-500.f)
{
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);

}

// Controls the scroll movement and entity movement
void World::update(sf::Time dt)
{
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());	// NO movement in X and y moves according the elapsed time

	sf::Vector2f position = mPlayerAircraft->getPosition();
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	if(position.x <= mWorldBounds.left + 150
		|| position.x >= mWorldBounds.left + mWorldBounds.width - 150)
	{
		velocity.x = -velocity.x;		// Flips players velocity resolting in moving back the airplane
		mPlayerAircraft->setVelocity(velocity);
	}

	mSceneGraph.update(dt);

}

// Sets the current view and delegates the drawing work to the scene graph
void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
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
	// Initialize the different scene layers (until we reach layercount)
	for (std::size_t i = 0; i < LayerCount; i++)
	{
		sceneNode::Ptr layer(new sceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));

	}
	

	// Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);		// Rect with the size as world bounding boxes 
	texture.setRepeated(true);					// Repeat itself 

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(
		new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add player's aircraft
	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mPlayerAircraft->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[Air]->attachChild(std::move(leader));

	// Add two escorting aircrafts, placed relatively to the main plane
	std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, mTextures));
	leftEscort->setPosition(-80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures));
	rightEscort->setPosition(80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(rightEscort));


}