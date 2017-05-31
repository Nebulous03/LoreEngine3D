#include "Renderer2D.h"

void Renderer::push(Entity* renderable)
{
	_renderQueue.push(renderable);
}

void Renderer::renderAll()
{
	while (!_renderQueue.empty())
	{
		Entity* entity = _renderQueue.front();
		entity->render();
		_renderQueue.pop();
	}
}
