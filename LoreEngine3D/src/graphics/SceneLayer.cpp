#include "SceneLayer.h"

SceneLayer::SceneLayer(BaseRenderer& renderer) : _renderer(renderer) {}

SceneLayer::~SceneLayer()
{
	//for (Renderable* renderable : _renderables)
	//	delete renderable;
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
			((BasicRenderer*)&_renderer)->push(entity->getParent()->getRenderable()->getTranslation());
			//((BasicRenderer*)&_renderer)->pop();
		}
		_renderer.push(entity->getRenderable());
	}
	_renderer.end();
	_renderer.flush();
}