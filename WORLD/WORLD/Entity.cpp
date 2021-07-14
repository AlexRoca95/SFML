#include "Entity.h"


// Sets velocity of the Entity using a vector
void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}
// Sets velocity of the Entity with floats
void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

// Now do the specific update for the entities (like movement)
void Entity::updateCurrent(sf::Time dt)
{
	move(mVelocity * dt.asSeconds());
}