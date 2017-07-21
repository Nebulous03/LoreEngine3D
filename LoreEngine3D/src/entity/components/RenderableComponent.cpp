#include "RenderableComponent.h"

RenderableComponent::RenderableComponent(Renderable& renderable) : Component(RENDER_COMPONENT_TYPE_ID), _renderable(&renderable) {}

RenderableComponent::~RenderableComponent()
{
	delete _renderable;
}

Renderable* RenderableComponent::getRenderable()
{
	return _renderable;
}