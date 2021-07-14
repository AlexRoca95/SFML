#ifndef SceneNode_H
#define SceneNode_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

// Class used to create the scene graph (a tree data structure consisting in multiples scene nodes).
// This is mainly used to manage objects and draw our scene
class sceneNode : public sf::Drawable, public sf::Transformable,
	private sf::NonCopyable		// NonCopyable --> SceneNode objects cannot be copied (copy constructor and assign operator are disbled)
{

public:
	typedef std::unique_ptr<sceneNode> Ptr;	// Typedef because we will use unique_ptr several times
	
	sceneNode();
	// Basic tree operations of scene graph
	void attachChild(Ptr);					// add a child node
	Ptr detachChild(const sceneNode&);		// remove a child node

	// Drawing functions
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;		
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

	// Update
	void update(sf::Time dt);

	sf::Transform getWorldTransform() const;
	sf::Vector2f getWorldPosition() const;

private:
	std::vector<Ptr> mChildren;				// We use the Ptr type that we defined previously
	sceneNode* mParent;
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);
};
#endif // !sceneNode.h
