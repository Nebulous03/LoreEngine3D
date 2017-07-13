#pragma once
#include "Shader.h"
#include "Renderable.h"
#include "Renderer.h"
#include <vector>

class SceneLayer
{
protected:

	BaseRenderer& _renderer;
	std::vector<Renderable*> _renderables;

public:

	SceneLayer(BaseRenderer& renderer);
	virtual ~SceneLayer();

	SceneLayer& add(Renderable* renderable);

	void render();

};