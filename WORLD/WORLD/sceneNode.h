#ifndef SceneNode_H
#define SceneNode_H

#include <vector>
#include <memory>

// Class used to create the scene graph (a tree data structure consisting in multiples scene nodes).
// This is mainly used to manage objects and draw our scene
class sceneNode {

public:
	typedef std::unique_ptr<sceneNode> Ptr;	// Typedef because we will use unique_ptr several times
	
	sceneNode();
	void attachChild(Ptr);					// add a child node
	Ptr detachChild(const sceneNode&);		// remove a child node

private:
	std::vector<Ptr> mChildren;				// We use the Ptr type that we defined previously
	sceneNode* mParent;


};
#endif // !sceneNode.h
