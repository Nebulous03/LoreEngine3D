#pragma once
#include "../math/Math.h"
#include "../graphics/Renderable.h"
#include "Component.h"
#include <vector>

class Entity
{
protected:

	Vector3f _position;
	Vector3f _rotation;
	Entity*  _parent;

	std::vector<Component*> _components;

	/* TEMP */

	Renderable* _renderable;

public:

	Entity(Renderable& renderable);
	virtual ~Entity();

	Entity& setPosition(float x, float y, float z);
	Entity& setPosition(Vector3f position);

	Entity& setRotation(float x, float y, float z);
	Entity& setRotation(Vector3f rotation);

	Vector3f& getPosition();
	Vector3f& getRotation();

	Entity& move();
	Entity& rotate();

	void parent(Entity& entity);
	Entity* getParent();

	void add(Component& component);
	void remove(Component& component);

	std::vector<Component*>* getComponents();

	/* TEMP */
	
	Renderable* getRenderable();

};