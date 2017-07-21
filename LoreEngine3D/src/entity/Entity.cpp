#include "Entity.h"

Entity::Entity(Renderable& renderable) : _renderable(&renderable) {}

Entity::~Entity() {
	delete _renderable;
}

Entity& Entity::setPosition(float x, float y, float z)
{
	return *this;
}

Entity& Entity::setPosition(Vector3f position)
{
	return *this;
}

Entity& Entity::setRotation(float x, float y, float z)
{
	return *this;
}

Entity& Entity::setRotation(Vector3f rotation)
{
	return *this;
}

Vector3f& Entity::getPosition()
{
	return Vector3f(0);
}

Vector3f& Entity::getRotation()
{
	return Vector3f(0);
}

Entity& Entity::move()
{
	return *this;
}

Entity& Entity::rotate()
{
	return *this;
}

void Entity::parent(Entity& entity)
{
	if (&entity != this && entity.getParent() != this)
		_parent = &entity;
	else std::cout << "CANNOT PARENT" << std::endl;
}

Entity* Entity::getParent()
{
	return _parent;
}

std::vector<Component*>* Entity::getComponents()
{
	return &_components;
}

Renderable* Entity::getRenderable()
{
	return _renderable;
}
