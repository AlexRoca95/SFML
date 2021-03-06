
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Entity.h"
#include "ResourceHolder.h"

class Aircraft : public Entity // Inherits inderectly from sceneNode
{
public:
	enum Type {	 // Different types of aircraft

		Eagle,
		Raptor,
	};

	explicit Aircraft(Type type, const ResourceHolder<sf::Texture, Textures::ID>&);
	virtual void drawCurrent(sf::RenderTarget&, sf::RenderStates) const;
private:
	Type mType;
	sf::Sprite mSprite; 
};


#endif // !AIRCRAFT_H

