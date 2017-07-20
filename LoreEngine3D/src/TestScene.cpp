#include "TestScene.h"
#include "graphics\Graphics.h"

#define LOG_TICK 1

TestScene::TestScene()
{
	_camera = new Camera(vec3f(0, 0, 0), CAMERA_PERSPECTIVE, 640.0f, 480.0f);
	_colorShader = new Shader("res/shaders/default.vs", "res/shaders/default.fs");
	_renderer = new BasicRenderer(*_colorShader, *_camera);

	_layer = new SceneLayer(*_renderer);

	_cubeMesh = loadMesh("res/meshs/cube.obj");
	_cubeMesh2 = loadMesh("res/meshs/cube.obj");

	_cube = new Renderable(*_cubeMesh, mat4f::Translation(0.0f, 0.0f, -3.0f));
	_cube2 = new Renderable(*_cubeMesh, mat4f::Translation(1.0f, 1.0f, 0.0f));

	Entity* cubeEntity = new Entity(*_cube);
	Entity* cubeEntity2 = new Entity(*_cube2);

	cubeEntity2->parent(*cubeEntity);

	_layer->add(*cubeEntity);
	_layer->add(*cubeEntity2);
}

TestScene::~TestScene()
{
	delete _cube;
	delete _cubeMesh;
	delete _cubeMesh2;
	delete _camera;
	delete _colorShader;
	delete _renderer;
	delete _layer;
}

void resizeCallback(Window& window, int width, int height)
{
	std::cout << "RESIZE" << std::endl;
}

void TestScene::onLoad(Game& game)
{
	game.getTickHandler().setTPSLimit(10.0);
	//_camera->resize(1920.0f, 1080.0f);
	//game.getGraphics().setDisplay(WINDOWED, 1920, 1080);
	game.getActiveWindow().setResizeCallback(resizeCallback);
}

void TestScene::onUnload(Game& game)
{

}

void TestScene::onTick(Game& game, double delta)
{
#if LOG_TICK
	printf("TICK:\n\tFPS:%d\n\tDELTA:%f\n\tMS:%f\n", 
		game.getTickHandler().getFPS(), delta, 
		game.getTickHandler().getRenderTime());
#endif
}

void TestScene::onUpdate(Game& game, double delta)
{
	if (Input::isKeyPressed(GLFW_KEY_Q))
	{
		_camera->rotate(vec3f(0, 1, 0), (float)delta * 0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_E))
	{
		_camera->rotate(vec3f(0, 1, 0), (float)delta * -0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_Z))
	{
		_camera->rotate(vec3f(1, 0, 0), (float)delta * 0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_X))
	{
		_camera->rotate(vec3f(1, 0, 0), (float)delta * -0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_UP))
	{
		_camera->move(vec3f(0, 1, 0), (float)delta * 1.0f);
	}

	if (Input::isKeyPressed(GLFW_KEY_DOWN))
	{
		_camera->move(vec3f(0, -1, 0), (float)delta * 1.0f);
	}

	if (Input::isKeyPressed(GLFW_KEY_LEFT))
	{
		_camera->move(vec3f(-1, 0, 0), (float)delta * 1.0f);
	}

	if (Input::isKeyPressed(GLFW_KEY_RIGHT))
	{
		_camera->move(vec3f(1, 0, 0), (float)delta * 1.0f);
	}

	if (Input::isKeyPressed(GLFW_KEY_G))
	{
		_camera->move(vec3f(0, 0, -1), (float)delta * 1.0f);
	}

	if (Input::isKeyPressed(GLFW_KEY_H))
	{
		_camera->move(vec3f(0, 0, 1), (float)delta * 1.0f);
	}

	if (Input::isKeyPressed(GLFW_KEY_Q))
	{

	}

	if (Input::isKeyPressed(GLFW_KEY_E))
	{

	}

}

void TestScene::onRender()
{
	_layer->render();
}