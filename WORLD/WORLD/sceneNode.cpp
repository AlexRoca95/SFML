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
