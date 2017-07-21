#pragma once
#include "Component.h"
#include "Entity.h"
#include <vector>
#include <map>

class EntityDatabase	//TODO: Make singleton
{
private:
	std::map<Entity*, std::vector<Component*>*> _entityMap;
	std::map<unsigned short, std::map<Entity*, Component*>> _componentMap;
public:
	void registerEntity(Entity* entity);
	void removeEntity(Entity* entity);

	Component& getComponent(Entity& entity, unsigned short type);

	const std::vector<Component*>& getComponents(Entity* entity);
	const std::map<Entity*, Component*>& getComponents(unsigned short type);
};