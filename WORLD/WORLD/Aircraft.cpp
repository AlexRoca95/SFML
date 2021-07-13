#include "Aircraft.h"


// GLOBAL FUNCTION. It selects the texture depending the type of the Aircraft
Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Eagle:
		return Textures::Eagle;
		
	case Aircraft::Raptor:
		return Textures::Raptor; // Returns ID of the texture
		
	default:
		return Textures::Eagle;
	}

}

// Initializes type of Aircraft. Also it initializes his sprite with a pointer to the texture dependind on 
// the type of the Aircraft
Aircraft::Aircraft(Type type, const ResourceHolder<sf::Texture, Textures::ID>& texture):
	mType(type), mSprite(texture.get(toTextureID(type)))
{
	// Change the sprite origin to the center (it's upper left corner by default)
	// This allows us to work in a more comfortable way for some tasks like rotation
	sf::FloatRect bounds = mSprite.getLocalBounds();				// Local bounding rectangle of the sprite
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);		// Origin set to the center of the sprite

}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(mSprite, states);		// Draw the sprite. Everything else is perfomed in sceneNode and in SFML

}
