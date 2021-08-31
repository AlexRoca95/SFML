
#ifndef SPRITENODE_H
#define SPRITENODE_H


#include "sceneNode.h"

// SpriteNode is sceneNode type which displays the background of our game through the sceneNode
class SpriteNode : public sceneNode
{
public:
	explicit SpriteNode(const sf::Texture&);
	SpriteNode(const sf::Texture&, sf::IntRect&);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	

	sf::Sprite mSprite;
};
#endif // !SPRITENODE_H

