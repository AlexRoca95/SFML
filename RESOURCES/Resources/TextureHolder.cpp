#include "TextureHolder.h"
#include "assert.h"				// For assert macro (handling logic errors)

using namespace sf;
using namespace std;

// Constructor
TextureHolder::TextureHolder()
{

}

// Method that loads a texture into our map.
// It has two arguments: one with the ID of the texture and the second one with name of the file
void TextureHolder::loadTexture(Textures::ID id, const std::string& pathFile)
{
	// Create a texture object and store it in a unique_ptr
	unique_ptr<Texture> texture(new Texture());
	
	if (!texture->loadFromFile(pathFile))		// Check if file could be uploaded
	{
		// Failed to load the file (Runtime error)
		throw runtime_error("TextureHolder::load - Failed to load " + pathFile);
	}

	// make_pair --> constructs a key-value pair for the map
	auto inserted = mTextureMap.insert(make_pair(id, move(texture)));

	// Macro that evaluates the expression (only in Debug mode) if it is false
	// a checkpoint is triggered, halting the program. 
	// You should only use this for error checks! When you know it works, you remove it
	assert(inserted.second);		// Second value of inserted has the boolean member of the pair

}

// Method that returns a reference to a texture
Texture& TextureHolder::get(Textures::ID id)
{
	// auto --> Keyword that automatically deduce the type of the initialization
	//			(in this case type iterator)
	// find --> Searchs in the map for an element with a key equivalent to id.
	//			Returns an iterator if it is found or an interator to map::end
	auto found = mTextureMap.find(id);

	// Check if texture was founded. Halt program if not
	assert(found != mTextureMap.end());		

	return *found->second;		// Returns the value of the pair key-value (2º one = value = texture)

}

// Method that returns a reference to a texture
// Alternative get mehtod in case we only have a pointer o reference to a const texture
const Texture& TextureHolder::get(Textures::ID id) const
{
	auto found = mTextureMap.find(id);
	assert(found != mTextureMap.end());

	return *found->second;		

}
