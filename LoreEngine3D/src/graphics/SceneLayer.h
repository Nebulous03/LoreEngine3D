#pragma once
#include "../entity/Entity.h"
#include "Shader.h"
#include "Renderable.h"
#include "Renderer.h"
#include <vector>

class SceneLayer
{
protected:

	BaseRenderer& _renderer;
	std::vector<Entity*> _entities;

public:

	SceneLayer(BaseRenderer& renderer);
	virtual ~SceneLayer();

	SceneLayer& add(Entity& entity);

	void render();

};