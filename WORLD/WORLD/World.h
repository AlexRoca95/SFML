

#ifndef WORLD_H
#define WORLD_H

#include "Aircraft.h"		// This header includes all other headers (sceneNode, Entity...)
#include <array>

// Everything that our games needs to work
class World : sf::NonCopyable					// We only have ONE world
{
public:
	explicit World(sf::RenderWindow&);
	void	 update(sf::Time);
	void	 draw();

private:

	void loadTextures();
	void buildScene();

	enum Layer {

		Background,
		Air,
		LayerCount
	};

	// Rendering data
	sf::RenderWindow& mWindow;		
	sf::View mWorldView;											// Worlds current view 
	ResourceHolder<sf::Texture, Textures::ID> mTextures;			// Contains all our textures
	sceneNode mSceneGraph;
	std::array<sceneNode*, LayerCount> mSceneLayers;

	// Logical data
	sf::FloatRect mWorldBounds;										// Dimensions of our world
	sf::Vector2f mSpawnPosition;									// Initial Plater position
	float mScrollSpeed;												// The speed with which the world is scrolled
	Aircraft* mPlayerAircraft;										// Player's aircraft

};


#endif // !WORLD_H

