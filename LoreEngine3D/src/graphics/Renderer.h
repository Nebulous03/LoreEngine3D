#pragma once
#include <queue>
#include "../entity/Entity.h"

class Renderer {

private:
	std::queue<Entity*> _renderQueue;

public:
	virtual void push(Entity* renderable);
	virtual void renderAll();

};