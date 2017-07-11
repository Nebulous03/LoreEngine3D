#include "TickHandler.h"
#include <iostream>

#include "..\graphics\Renderer.h"
#include "..\graphics\Renderable.h"
#include "..\graphics\Shader.h"
#include "..\graphics\buffers\Buffers.h"
#include "..\graphics\Mesh.h"
#include "..\utils\OBJLoader.h"
#include "..\graphics\Camera.h"
#include "..\graphics\SceneLayer.h"

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

	Camera* camera = new Camera(vec3f(0,0,0), CAMERA_PERSPECTIVE, 640.0f, 480.0f);
	Shader* color = new Shader("res/shaders/default.vs", "res/shaders/default.fs");
	BasicRenderer* renderer = new BasicRenderer(color, camera);

	SceneLayer layer(renderer);

	Mesh cubeMesh = loadMesh("res/meshs/cube.obj");
	Renderable* cube = new Renderable(&cubeMesh, &mat4f::Translation(0.0f, 0.0f, -3.0f));

	layer.add(cube);

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

		//Keys:

		if (Input::isKeyPressed(GLFW_KEY_UP))
		{
			camera->move(vec3f(0, 1, 0), 0.05f);
		}

		if (Input::isKeyPressed(GLFW_KEY_DOWN))
		{
			camera->move(vec3f(0, -1, 0), 0.05f);
		}

		if (Input::isKeyPressed(GLFW_KEY_LEFT))
		{
			camera->move(vec3f(-1, 0, 0), 0.05f);
		}

		if (Input::isKeyPressed(GLFW_KEY_RIGHT))
		{
			camera->move(vec3f(1, 0, 0), 0.05f);
		}

		if (Input::isKeyPressed(GLFW_KEY_G))
		{
			camera->move(vec3f(0, 0, -1), 0.05f);
		}

		if (Input::isKeyPressed(GLFW_KEY_H))
		{
			camera->move(vec3f(0, 0, 1), 0.05f);
		}

		if (Input::isKeyPressed(GLFW_KEY_Q))
		{
	
		}

		if (Input::isKeyPressed(GLFW_KEY_E))
		{
	
		}

		renderer->push(cube);
		renderer->flush();

		/* END TEST CODE */

		_game->getActiveWindow()->update();

		// INPUT
		_game->getInput()->update();
	}
}