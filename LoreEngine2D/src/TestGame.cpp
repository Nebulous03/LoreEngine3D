#include "TestGame.h"
#include "TestInstance.h"
#include <iostream>

void TestGame::onStart()
{
	std::cout << "TestGame - On Start" << std::endl;
	TestInstance* inst = new TestInstance();				// Create Instance
	loadInstance(inst);			// Load Instace
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