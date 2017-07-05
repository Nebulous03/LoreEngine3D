#include "TestGame.h"
#include "TestScene.h"
#include "logic\Input.h"
#include <iostream>

void TestGame::onStart()
{
	std::cout << " TestGame - On Start" << std::endl;
	TestScene* scene = new TestScene();						// Create Instance
	loadScene(scene);										// Load Instace
}

void TestGame::onStop()
{
	std::cout << " TestGame - On Stop" << std::endl;
}

void TestGame::onTick()
{
	
}

void TestGame::onUpdate()
{
	if (Input::isKeyPressed(GLFW_KEY_A)) {
		std::cout << "PRESSED " << "A" << "!" << std::endl;
	}

	if (Input::isButtonPressed(GLFW_MOUSE_BUTTON_1)) {
		std::cout << Input::getMousePos() << std::endl;
	}
}