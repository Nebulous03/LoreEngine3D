#include "TestInstance.h"
#include <iostream>

TestInstance::TestInstance()
{

}

void TestInstance::onLoad()
{
	std::cout << "Instance Loaded!" << std::endl;
}

void TestInstance::onUnload()
{
	std::cout << "Instance Unloaded!" << std::endl;
}

void TestInstance::onTick()
{

}

void TestInstance::onUpdate()
{

}