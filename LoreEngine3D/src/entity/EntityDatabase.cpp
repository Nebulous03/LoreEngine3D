#include "EntityDatabase.h"

EntityDatabase::~EntityDatabase()
{
	//TODO
}

void EntityDatabase::registerEntity(Entity* entity)
{
	_entityMap.emplace(entity, entity->getComponents());

	for (Component* c : _entityMap[entity]) {
		std::map<Entity*, Component*> map;
		map.emplace(entity, c);
		_componentMap.emplace(c->getType(), map);
	}
	entity->link(this);
}

void EntityDatabase::removeEntity(Entity* entity)
{
	_entityMap.erase(entity);

	for (Component* c : entity->getComponents()) {
		_componentMap[c->getType()].erase(entity);
		if (_componentMap[c->getType()].empty())
			_componentMap.erase(c->getType());
	}
}

void EntityDatabase::addComponent(Entity* entity, Component* component)
{
	_entityMap[entity].push_back(component);
	_componentMap[component->getType()].emplace(entity, component);
}

void EntityDatabase::removeComponent(Entity* entity, Component* component)
{
	std::vector<Component*> map = _entityMap[entity];
	auto location = std::find(map.begin(), map.end(), component);
	if(location != map.end()) map.erase(location);
	else std::cout << " Unable to remove Component!" << std::endl;

	_componentMap[component->getType()].erase(entity);
}

bool EntityDatabase::hasComponent(Entity* entity, unsigned short type)
{
	if (_componentMap[type].find(entity) != _componentMap[type].end())
		return true;
	else
		return false;
}

Component& EntityDatabase::getComponent(Entity& entity, unsigned short type)
{
	return *_componentMap[type][&entity];
}

std::vector<Component*>& EntityDatabase::getComponents(Entity* entity)
{
	return _entityMap[entity];
}

std::map<Entity*, Component*>& EntityDatabase::getComponents(unsigned short type)
{
	return _componentMap[type];
}