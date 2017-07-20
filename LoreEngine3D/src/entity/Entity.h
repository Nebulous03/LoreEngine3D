#pragma once
#include "../math/Math.h"
#include "../graphics/Renderable.h"

class Entity
{
protected:

	Vector3f _position;
	Vector3f _rotation;
	Entity*  _parent;

	Renderable* _renderable; // TEMP

public:

	Entity(Renderable& renderable);

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

	Renderable* getRenderable();
};