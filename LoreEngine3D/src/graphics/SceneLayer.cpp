#include "SceneLayer.h"

SceneLayer::SceneLayer(BaseRenderer& renderer) : _renderer(renderer) {}

SceneLayer::~SceneLayer()
{
	for (Entity* entity : _entities)
		delete entity;
}

SceneLayer& SceneLayer::add(Entity& entity)
{
	_entities.push_back(&entity);
	return *this;
}

void SceneLayer::render()
{
	_renderer.begin();
	for (Entity* entity : _entities) {
		if (entity->getParent() != nullptr)
		{
			((BasicRenderer*)&_renderer)->push(entity->getParent()->getRenderable()->getTransform());
			_renderer.submit(entity->getRenderable());
			((BasicRenderer*)&_renderer)->pop();
		}
		else
			_renderer.submit(entity->getRenderable());
	}
	_renderer.end();
	_renderer.flush();
}