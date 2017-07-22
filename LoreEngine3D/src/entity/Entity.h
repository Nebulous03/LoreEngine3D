#pragma once
#include "../math/Math.h"
#include "../graphics/Renderable.h"
#include "Component.h"
#include "EntityDatabase.h"
#include <vector>

class EntityDatabase;

class Entity
{
protected:

	Vector3f _position;
	Vector3f _rotation;
	Entity*  _parent;

	std::vector<Component*> _tempComponents;
	EntityDatabase* _entityDatabase;

public:

	virtual ~Entity();

	void link(EntityDatabase* database);

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

	std::vector<Component*>& getComponents();

};