#include "TestScene.h"
#include <iostream>
#include <GL\glew.h>

TestScene::TestScene()
{

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
	
}

void TestScene::onRender()
{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glEnd();
}