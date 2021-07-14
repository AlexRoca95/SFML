
#ifndef ENTITY_H
#define ENTITY_H

#include "sceneNode.h"

class Entity : public sceneNode  // Inherits sceneNode so that entities can be rendered by SFML
{

public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
private:
	sf::Vector2f mVelocity;		// Automatically initialized to zere by default constructor
	virtual void updateCurrent(sf::Time);

};


#endif // !ENTITY_H

