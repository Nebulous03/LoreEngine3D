#include "SceneLayer.h"

SceneLayer::SceneLayer(BaseRenderer* renderer) : _renderer(renderer) {}

SceneLayer::~SceneLayer()
{
	delete _renderer;
	for (Renderable* renderable : _renderables)
		delete renderable;
}

SceneLayer& SceneLayer::add(Renderable* renderable)
{
	_renderables.push_back(renderable);
	return *this;
}