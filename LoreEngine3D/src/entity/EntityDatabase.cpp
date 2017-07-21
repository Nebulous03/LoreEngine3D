#include "EntityDatabase.h"

void EntityDatabase::registerEntity(Entity* entity)
{
	_entityMap[entity] = entity->getComponents();

	for (Component* c : *entity->getComponents())
		_componentMap[c->getType()][entity] = c;
}

void EntityDatabase::removeEntity(Entity* entity)
{
	_entityMap.erase(entity);

	for (Component* c : *entity->getComponents()) {
		_componentMap[c->getType()].erase(entity);
		if (_componentMap[c->getType()].empty())
			_componentMap.erase(c->getType());
	}
}

Component& EntityDatabase::getComponent(Entity& entity, unsigned short type)
{
	return *_componentMap[type][&entity];
}

const std::vector<Component*>& EntityDatabase::getComponents(Entity* entity)
{
	return *_entityMap[entity];
}

const std::map<Entity*, Component*>& EntityDatabase::getComponents(unsigned short type)
{
	return _componentMap[type];
}