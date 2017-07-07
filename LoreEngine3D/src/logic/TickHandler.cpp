#include "TickHandler.h"
#include <iostream>

#include "..\graphics\Renderer.h"
#include "..\graphics\Renderable.h"
#include "..\graphics\Shader.h"
#include "..\graphics\buffers\Buffers.h"
#include "..\graphics\Mesh.h"

TickHandler::TickHandler(Game& game, double UPS)
{
	_game = &game;
	_UPS = UPS;
}

void TickHandler::run()
{
	_game->initialize();
	_game->onStart();



	/* TEST CODE */

	GLfloat colors[] =
	{
		0,0,1,1,
		0,1,0,1,
		1,0,1,1,
		1,0,0,1
	};

	GLfloat colors2[] =
	{
		0,0,1,1,
		0,1,0,1,
		1,0,1,1,
		1,0,0,1
	};

	BasicRenderer renderer;
	Shader color("res/shaders/default.vs", "res/shaders/default.fs");
	color.bind();

	Mesh plane = Mesh::Plane(1, 1, colors, 16);
	Mesh plane2 = Mesh::Plane(0.5f, 0.5f, colors2, 16);

	Matrix4f s1Trans = mat4f::Translation(-0.5f, -0.5f, 0);
	Matrix4f s2Trans = mat4f::Translation(0, 0, 0);
	std::cout << s1Trans << std::endl;

	Renderable square(plane, color, s1Trans);
	Renderable square2(plane2, color, s2Trans);

	/* END TEST CODE */



	while (_game->getStatus())
	{
		if (glfwWindowShouldClose(_game->getActiveWindow()->getGLWindow())){
			_game->stop(); break;
		}

		// Update
		_game->onUpdate();

		// RENDER
		_game->getActiveWindow()->clear();
		_game->getActiveScene()->onRender();	// Swap with something better


		/* TEST CODE */

		renderer.push(square);
		renderer.push(square2);
		renderer.flush();

		/* END TEST CODE */


		_game->getActiveWindow()->update();


		// INPUT
		_game->getInput()->update();
	}
}