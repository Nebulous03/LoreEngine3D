#include "TestScene.h"
#include "graphics\shaders\Shader.h"
#include "graphics\buffers\Buffers.h"
#include "logic\Input.h"
#include <iostream>
#include <GL\glew.h>

TestScene::TestScene()
{
	/* TEST CODE BELOW */

	GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,

	};

	GLushort indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLfloat color[] =
	{
		1,0,0,1,
		0,1,0,1,
		0,0,1,1,
		1,1,1,1
	};

#if 0
	GLfloat vertices[] =
	{
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLuint vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#endif

	VertexArray vao;
	IndexBuffer ibo(indices, 6);

	vao.add(new Buffer(vertices, 4 * 3, 3), 0);
	vao.add(new Buffer(color,    4 * 4, 4), 1);
	vao.bind();

	ibo.bind();

	Matrix4f ortho = Matrix4f::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("res/shaders/default.vs", "res/shaders/default.fs");
	shader.bind();

	//shader.setUniform("projection", ortho);
	//shader.setUniform("model", mat4f::Translation(4.0f, 3.0f, 0.0f));
	//shader.setUniform("shader_color", vec4f(1.0f, 1.0f, 1.0f, 1.0f));

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
	//glDrawArrays(GL_TRIANGLES, 0, 6);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}