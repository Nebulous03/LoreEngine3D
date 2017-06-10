#include "TestGame.h"
#include "TestScene.h"
#include <iostream>

void TestGame::onStart()
{
	std::cout << "TestGame - On Start" << std::endl;
	TestScene* scene = new TestScene();						// Create Instance
	loadScene(scene);										// Load Instace
}

void TestGame::onStop()
{
	std::cout << "TestGame - On Stop" << std::endl;
}

void TestGame::onTick()
{

}

void TestGame::onUpdate()
{

}