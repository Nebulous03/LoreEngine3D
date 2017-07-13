#include "TestScene.h"

TestScene::TestScene()
{
	_camera = new Camera(vec3f(0, 0, 0), CAMERA_PERSPECTIVE, 640.0f, 480.0f);
	_colorShader = new Shader("res/shaders/default.vs", "res/shaders/default.fs");
	_renderer = new BasicRenderer(*_colorShader, *_camera);

	_layer = new SceneLayer(*_renderer);

	_cubeMesh = loadMesh("res/meshs/cube.obj");
	_cube = new Renderable(*_cubeMesh, mat4f::Translation(0.0f, 0.0f, -3.0f));

	_layer->add(_cube);
}

TestScene::~TestScene()
{
	delete _cube;
	delete _cubeMesh;
	delete _camera;
	delete _colorShader;
	delete _renderer;
	delete _layer;
}

void TestScene::onLoad()
{

}

void TestScene::onUnload()
{

}

void TestScene::onTick()
{

}

void TestScene::onUpdate()
{
	if (Input::isKeyPressed(GLFW_KEY_Q))
	{
		_camera->rotate(vec3f(0, 1, 0), 0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_E))
	{
		_camera->rotate(vec3f(0, 1, 0), -0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_Z))
	{
		_camera->rotate(vec3f(1, 0, 0), 0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_X))
	{
		_camera->rotate(vec3f(1, 0, 0), -0.25f);
	}

	if (Input::isKeyPressed(GLFW_KEY_UP))
	{
		_camera->move(vec3f(0, 1, 0), 0.05f);
	}

	if (Input::isKeyPressed(GLFW_KEY_DOWN))
	{
		_camera->move(vec3f(0, -1, 0), 0.05f);
	}

	if (Input::isKeyPressed(GLFW_KEY_LEFT))
	{
		_camera->move(vec3f(-1, 0, 0), 0.05f);
	}

	if (Input::isKeyPressed(GLFW_KEY_RIGHT))
	{
		_camera->move(vec3f(1, 0, 0), 0.05f);
	}

	if (Input::isKeyPressed(GLFW_KEY_G))
	{
		_camera->move(vec3f(0, 0, -1), 0.05f);
	}

	if (Input::isKeyPressed(GLFW_KEY_H))
	{
		_camera->move(vec3f(0, 0, 1), 0.05f);
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
	//_timer.reset();

	_layer->render();

	//printf("%f ms\n", _timer.elapsed() * 1000.0);
}