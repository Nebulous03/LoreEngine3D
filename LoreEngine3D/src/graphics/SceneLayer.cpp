#include "SceneLayer.h"
#include "../entity/components/RenderableComponent.h"

SceneLayer::SceneLayer(BaseRenderer& renderer) : _renderer(renderer)
{
	_entityDatabase = new EntityDatabase();
}

SceneLayer::~SceneLayer()
{
	delete _entityDatabase;
}

SceneLayer& SceneLayer::add(Entity& entity)
{
	_entityDatabase->registerEntity(&entity);
	return *this;
}

typedef std::map<Entity*, Component*> component_map;

void SceneLayer::render()
{
	_renderer.begin();

	component_map map = _entityDatabase->getComponents(COMPONENT_TYPE_RENDERABLE);
	for (component_map::iterator it = map.begin(); it != map.end(); ++it)
	{
		if (it->first->getParent() != nullptr)
		{
			//((BasicRenderer*)&_renderer)->push(it->first->getParent()->getRenderable()->getTransform());
			_renderer.submit(((RenderableComponent*)it->second)->getRenderable());
			//((BasicRenderer*)&_renderer)->pop();
		}
		else
		{
			_renderer.submit(((RenderableComponent*)it->second)->getRenderable());
		}
	}

	_renderer.end();
	_renderer.flush();
}