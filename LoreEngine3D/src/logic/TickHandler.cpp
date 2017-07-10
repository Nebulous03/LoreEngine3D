#include "TickHandler.h"
#include <iostream>

#include "..\graphics\Renderer.h"
#include "..\graphics\Renderable.h"
#include "..\graphics\Shader.h"
#include "..\graphics\buffers\Buffers.h"
#include "..\graphics\Mesh.h"
#include "..\utils\OBJLoader.h"

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

	/*

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

	*/

	GLfloat colors[] =
	{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};

	BasicRenderer renderer;
	Shader color("res/shaders/default.vs", "res/shaders/default.fs");
	color.bind();

	Matrix4f s1Trans = mat4f::Translation(0.0f, 0.0f, -3.0f) * mat4f::Rotation(vec3f(1,1,0), -45.0f);
	Matrix4f s2Trans = mat4f::Translation(0, 0, 0);

	/*

	Mesh plane = Mesh::Plane(1, 1, colors, 16);
	Mesh plane2 = Mesh::Plane(0.5f, 0.5f, colors2, 16);

	std::cout << s1Trans << std::endl;

	Renderable square(plane, color, s1Trans);
	Renderable square2(plane2, color, s2Trans);

	*/

	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_FRONT);

	Mesh cubeMesh = loadMesh("res/meshs/cube.obj", colors, 36);
	Renderable cube(cubeMesh, color, s1Trans); //mat4f::Translation(vec3f(0)));

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

		if (Input::isKeyPressed(GLFW_KEY_UP))
		{
			*cube.getTranslation() *= mat4f::Translation(vec3f(0, 0.01f,0));
		}

		if (Input::isKeyPressed(GLFW_KEY_DOWN))
		{
			*cube.getTranslation() *= mat4f::Translation(vec3f(0, -0.01f, 0));
		}

		if (Input::isKeyPressed(GLFW_KEY_LEFT))
		{
			*cube.getTranslation() *= mat4f::Translation(vec3f(0.01f, 0, 0));
		}

		if (Input::isKeyPressed(GLFW_KEY_RIGHT))
		{
			*cube.getTranslation() *= mat4f::Translation(vec3f(-0.01f, 0, 0));
		}

		if (Input::isKeyPressed(GLFW_KEY_G))
		{
			*cube.getTranslation() *= mat4f::Translation(vec3f(0, 0, 0.01f));
		}

		if (Input::isKeyPressed(GLFW_KEY_H))
		{
			*cube.getTranslation() *= mat4f::Translation(vec3f(0, 0, -0.01f));
		}

		if (Input::isKeyPressed(GLFW_KEY_Q))
		{
			*cube.getTranslation() *= mat4f::Rotation(vec3f(1.0f, 1.0f, 0.0f), -0.2f);
		}

		if (Input::isKeyPressed(GLFW_KEY_E))
		{
			*cube.getTranslation() *= mat4f::Rotation(vec3f(1.0f, 1.0f, 0.0f), 0.2f);
		}

		//renderer.push(square);
		//renderer.push(square2);
		renderer.push(cube);
		renderer.flush();

		/* END TEST CODE */


		_game->getActiveWindow()->update();


		// INPUT
		_game->getInput()->update();
	}
}