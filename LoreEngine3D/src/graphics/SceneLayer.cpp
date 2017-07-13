#include "SceneLayer.h"

SceneLayer::SceneLayer(BaseRenderer& renderer) : _renderer(renderer) {}

SceneLayer::~SceneLayer()
{
	//for (Renderable* renderable : _renderables)
	//	delete renderable;
}

SceneLayer& SceneLayer::add(Renderable* renderable)
{
	_renderables.push_back(renderable);
	return *this;
}

void SceneLayer::render()
{
	_renderer.begin();
	for (Renderable* renderable : _renderables)
		_renderer.push(renderable);
	_renderer.end();
	_renderer.flush();
}