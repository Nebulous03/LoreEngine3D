#pragma once
#include "../Component.h"
#include "../../graphics/Renderable.h"

#define COMPONENT_TYPE_RENDERABLE 2

class RenderableComponent : public Component
{
protected:
	Renderable* _renderable;
public:
	RenderableComponent(Renderable& renderable);
	~RenderableComponent();

	Renderable* getRenderable();
};