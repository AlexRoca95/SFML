
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Entity.h"

class Aircraft : public Entity // Inherits inderectly from sceneNode
{
public:
	enum Type {	 // Different types of aircraft

		Eagle,
		Raptor,
	};

	explicit Aircraft(Type type);
private:
	Type mType;

};


#endif // !AIRCRAFT_H

