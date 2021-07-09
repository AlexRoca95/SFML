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