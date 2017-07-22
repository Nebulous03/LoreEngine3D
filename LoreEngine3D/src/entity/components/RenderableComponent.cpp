#include "RenderableComponent.h"

RenderableComponent::RenderableComponent(Renderable& renderable) : Component(COMPONENT_TYPE_RENDERABLE), _renderable(&renderable) {}

RenderableComponent::~RenderableComponent()
{
	delete _renderable;
}

Renderable* RenderableComponent::getRenderable()
{
	return _renderable;
}