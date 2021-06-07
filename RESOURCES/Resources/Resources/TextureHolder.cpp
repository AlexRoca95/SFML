#include "TextureHolder.h"

using namespace sf;
using namespace std;

// Constructor
TextureHolder::TextureHolder()
{

}

// Method that loads a texture into our map.
// It has two arguments: one with the ID of the texture and the second one with name of the file
void TextureHolder::loadTexture(Textures::ID id, const std::string& filename)
{
	// Create a texture object and store it in a unique_ptr
	unique_ptr<Texture> texture(new Texture());
	texture->loadFromFile(filename);

	// make_pair --> constructs a key-value pair for the map
	mTextureMap.insert(make_pair(id, move(texture)));

}

// Method that returns a reference to a texture
Texture& TextureHolder::get(Textures::ID id)
{
	// auto --> Keyword that automatically deduce the type of the initialization
	//			(in this case type iterator)
	// find --> Searchs in the map for an element with a key equivalent to id.
	//			Returns an iterator if it is found or an interator to map::end
	auto found = mTextureMap.find(id);

	return *found->second;		// Returns the value of the pair key-value (2º one = value = tetture)

}

