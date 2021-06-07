#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <SFML/Graphics.hpp>

// We nest our enum into a namespace so it gives us a scope for them.
// This way when we use them we will need to use the Textures:: prefix 
// which clearly describes the intention and avoid possible name collisions
namespace Textures
{
	enum ID {Landscape, Airplane, Missile};
}


class TextureHolder
{
private:
	// This is a map where we store a key-value pair.
	// In this case it associate a texture ID with a pointer 
	// to the texture that needs to be loaded with that ID
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

public:
	TextureHolder();
	void loadTexture(Textures::ID, const std::string&);
	sf::Texture& get(Textures::ID);
};




#endif
