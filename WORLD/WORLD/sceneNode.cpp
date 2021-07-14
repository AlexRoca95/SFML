#include "sceneNode.h"

#include "assert.h"



sceneNode::sceneNode():mParent(nullptr)
{



}

// Function to add a child node
void sceneNode::attachChild(Ptr child)
{	
	child->mParent = this;						// Parent node of child will be this node
	mChildren.push_back(std::move(child));		// We insert child at the end of the vector
	
}

// Function to remove a child from the node
sceneNode::Ptr sceneNode::detachChild(const sceneNode& node)
{
	
	// We use a Lambda expression --> They allow to define a local function 
	// inside other function
	// Parts : [&] -> Captures all variables by reference
	//		   (Ptr& p) -> Parameter list for the local function
	//		   -> bool -> return type for the function (bool in this case)
	//			The function body enclosed by {}
	auto found = std::find_if(mChildren.begin(), mChildren.end(),
		[&](Ptr& p) -> bool {return p.get() == &node; });			

	assert(found != mChildren.end());		// Check if node was founded. If false, program is halted

	Ptr child = std::move(*found);			// Move the found node out of the container
	child->mParent = nullptr;
	mChildren.erase(found);
	
	
	return child;

}


// Overrided draw function of sf::Drawable to render the whole scene node
void sceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// We have to deal with two diferent transforms. 
	// - First, with the transform of the current node wich determines his position, 
	// scale and rotation relative to the parent node (getTransform() provide us that)
	// - Secondly, the absolute transform of the parent node (info of where to render it)
	// which is holded in the parameter states.
	states.transform *= getTransform();  // Now states.transform holds the absolute world transform
	
	drawCurrent(target, states);		// Draw the derived object

	// We draw all the child nodes. itr will point to the child node
	for (auto itr = mChildren.begin(); itr!= mChildren.end(); ++itr)
	{
		(*itr)->draw(target, states);
	}

}

// Draw function that only draws the current object but not the children
void sceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Does nothing by default. Derived classes will override it
}


void sceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

// Update of the current Node
void sceneNode::updateCurrent(sf::Time dt)
{
	// Does nothing by default. Derived classes will override it and do specefic update functionality
}

// Updates all the children nodes
void sceneNode::updateChildren(sf::Time dt)
{
	for (auto itr = mChildren.begin(); itr != mChildren.end(); ++itr)
	{
		(*itr)->update(dt);
	}
}

// Takes into account all the transforms of the parent nodes
sf::Transform sceneNode::getWorldTransform() const
{
	// Represents the identity of the transform (clarifies the way how transforms are applied from the beginning)
	sf::Transform transform = sf::Transform::Identity;	

	for (const sceneNode *node = this; node != nullptr; node = node->mParent)
	{
		transform = node->getTransform() * transform;
	}

	return transform;
}

// Returns the absolute position of the world
sf::Vector2f sceneNode::getWorldPosition() const
{
	sf::Vector2f absolutePos = getWorldTransform() * sf::Vector2f();

	return absolutePos;

}

