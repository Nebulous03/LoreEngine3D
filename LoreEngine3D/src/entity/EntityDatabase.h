#pragma once
#include "Component.h"
#include "Entity.h"
#include <vector>
#include <map>

class Entity;	// I Hate this

class EntityDatabase
{
private:
	std::map<Entity*, std::vector<Component*>> _entityMap;
	std::map<unsigned short, std::map<Entity*, Component*>> _componentMap;
public:
	~EntityDatabase();
	void registerEntity(Entity* entity);
	void removeEntity(Entity* entity);

	void addComponent(Entity* entity, Component* component);
	void removeComponent(Entity* entity, Component* component);

	bool hasComponent(Entity* entity, unsigned short type);

	Component& getComponent(Entity& entity, unsigned short type);

	std::vector<Component*>& getComponents(Entity* entity);
	std::map<Entity*, Component*>& getComponents(unsigned short type);
};