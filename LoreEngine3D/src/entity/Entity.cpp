#include "Entity.h"

void Entity::link(EntityDatabase* database)
{
	_entityDatabase = database;
}

Entity::~Entity() {
	
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

void Entity::add(Component& component)
{
	if (_entityDatabase == nullptr)
		_tempComponents.push_back(&component);
	else
		_entityDatabase->addComponent(this, &component);
}

void Entity::remove(Component& component)
{
	if (_entityDatabase == nullptr)
	{
		auto location = std::find(_tempComponents.begin(), _tempComponents.end(), &component);
		if (location != _tempComponents.end()) _tempComponents.erase(location);
	}
	else
		_entityDatabase->removeComponent(this, &component);
}

std::vector<Component*>& Entity::getComponents()
{
	if (_entityDatabase == nullptr)
		return _tempComponents;
	else 
		return _entityDatabase->getComponents(this);
}

