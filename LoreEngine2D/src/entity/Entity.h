#pragma once
#include "../math/Math.h"

// TODO: Make componenet based 
// (Currently not componenet based for simplicity)

class Entity {

protected:
	uint  _id;
	vec3f _pos;
	vec3f _scale;

public:
	Entity();
	Entity(vec3f pos, vec3f scale);

};
