#pragma once
#include "../../entity/Entity.h"
#include <GLFW\glfw3.h>

class Renderable : public Entity {

protected:
	Renderable();
public:
	virtual void render() = 0;

};
