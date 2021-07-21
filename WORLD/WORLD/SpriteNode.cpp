
#include "SpriteNode.h"



spriteNode::spriteNode(const sf::Texture& texture)
	:mSprite(texture)
{

}

spriteNode::spriteNode(const sf::Texture& texture, sf::IntRect& rect)
	: mSprite(texture, rect)
{

}


void spriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}