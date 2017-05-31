#include "Entity.h"

Entity::Entity(vec3f pos, vec3f scale) :
	_id(0), _pos(pos), _scale(scale) {}

Entity::Entity() :
	_id(0), _pos(vec3f(0, 0, 0)), _scale(vec3f(0, 0, 0)) {}