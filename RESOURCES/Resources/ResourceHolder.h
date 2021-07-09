#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include "assert.h"				// For assert macro (handling logic errors)

// We nest our enum into a namespace so it gives us a scope for them.
// This way when we use them we will need to use the Textures:: prefix 
// which clearly describes the intention and avoid possible name collisions
namespace Textures
{
	enum ID {Landscape, Airplane, Missile};
}

// We use a template class so it can be used with every type of resource
template <typename Resource, typename Identifier>
class ResourceHolder
{
private:
	// This is a map where we store a key-value pair.
	// In this case it associate a texture ID with a pointer 
	// to the rersource that needs to be loaded with that ID
	std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;

public:
	void load(Identifier, const std::string&);
	template <typename Parameter>
	void load(Identifier, const std::string&, const Parameter&);
	Resource& get(Identifier);
	const Resource& get(Identifier) const;
};


//REMEMBER! THE DECLARATIONS AND DEFINITIONS OF A CLASS TEMPLETE SHOULD ALL BE IN THE SAME HEADER FILE

// Method that loads a resource into our map.
// It has two arguments: one with the ID of the resource and the second one with name of the file
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& pathFile)
{
	// Create a resource object and store it in a unique_ptr
	std::unique_ptr<Resource> resource(new Resource());

	if (!resource->loadFromFile(pathFile))		// Check if file could be uploaded
	{
		// Failed to load the file (Runtime error)
		throw std::runtime_error("ResourceHolder::load - Failed to load " + pathFile);
	}

	// make_pair --> constructs a key-value pair for the map
	auto inserted = mResourceMap.insert(make_pair(id, move(resource)));

	// Macro that evaluates the expression (only in Debug mode) if it is false
	// a checkpoint is triggered, halting the program. 
	// You should only use this for error checks! When you know it works, you remove it
	// This Check if we insert a duplicated ID
	assert(inserted.second);		// Second value of inserted has the boolean member of the pair

}

// Method that loads a Shader. 
// An overloaded function for load is needed because the loadFromFile needs two arguments in order to load
// both vertex and fragment shader
template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& pathFile, const Parameter& secondParam)
{
	
	std::unique_ptr<Resource> resource(new Resource());

	if (!resource->loadFromFile(pathFile, secondParam))		// Check if file could be uploaded
	{
		// Failed to load the file (Runtime error)
		throw std::runtime_error("ResourceHolder::load - Failed to load " + pathFile);
	}

	auto inserted = mResourceMap.insert(make_pair(id, move(resource)));

	assert(inserted.second);

}

// Method that returns a reference to a resource
template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	// auto --> Keyword that automatically deduce the type of the initialization
	//			(in this case type iterator)
	// find --> Searchs in the map for an element with a key equivalent to id.
	//			Returns an iterator if it is found or an interator to map::end
	auto found = mResourceMap.find(id);

	// Check if resource was founded. Halt program if not
	assert(found != mResourceMap.end());

	return *found->second;		// Returns the value of the pair key-value (2º one = value = resource)

}

// Method that returns a reference to a resource
// Alternative get mehtod in case we only have a pointer o reference to a const resource
template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;

}




#endif
