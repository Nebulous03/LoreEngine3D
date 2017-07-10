#include "TestScene.h"
#include "utils\OBJLoader.h"
#include "logic\Input.h"
#include <iostream>
#include <GL\glew.h>

TestScene::TestScene()
{
	//Mesh m = loadMesh("res/mesh/cube.mesh");
}

void TestScene::onLoad()
{
	std::cout << " Instance Loaded!" << std::endl;
}

void TestScene::onUnload()
{
	std::cout << " Instance Unloaded!" << std::endl;
}

void TestScene::onTick()
{

}

void TestScene::onUpdate()
{
	if (Input::isKeyPressed(GLFW_KEY_A)) {
		std::cout << "PRESSED " << "A" << "!" << std::endl;
	}

	if (Input::isButtonPressed(GLFW_MOUSE_BUTTON_1)) {
		std::cout << Input::getMousePos() << std::endl;
	}
}

void TestScene::onRender()
{
	
}