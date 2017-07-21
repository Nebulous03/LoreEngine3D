#pragma once
#include "../Component.h"
#include "../../graphics/Renderable.h"

#define RENDER_COMPONENT_TYPE_ID 2

class RenderableComponent : public Component
{
protected:
	Renderable* _renderable;
public:
	RenderableComponent(Renderable& renderable);
	~RenderableComponent();

	Renderable* getRenderable();
};