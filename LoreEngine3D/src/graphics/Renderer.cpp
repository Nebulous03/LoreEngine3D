#include "Renderer.h"
#include "buffers\Buffers.h"
#include <cstdio>
#include <iostream>

#define PRINT_RENDER_QUEUE 0

RenderAction::RenderAction(uint8_t actionID, void* data) : actionID(actionID), data(data) {}

/* BASIC RENDERER */

BaseRenderer::BaseRenderer(Shader& shader, Camera& camera) : _shader(shader), _camera(camera) {}

BasicRenderer::BasicRenderer(Shader& shader, Camera& camera) : BaseRenderer(shader, camera)
{
	_transformStack.push_back(Matrix4f::Identity());
	_lastTransform = &_transformStack.back();
}

BaseRenderer::~BaseRenderer() {}

void BaseRenderer::begin() {}

void BaseRenderer::end() {}

void BasicRenderer::flush()
{

#if PRINT_RENDER_QUEUE

	for (RenderAction* action : _renderQueue)
	{
		printf("[%d]", action->actionID);
		switch (action->actionID) {
		case ACTION_NONE:
			printf("ACTION_NONE\n"); break;
		case ACTION_RENDER_TRIANGLES:
			printf("ACTION_RENDER_TRIANGLES\n"); break;
		case ACTION_RENDER_LINES:
			printf("ACTION_RENDER_LINES\n"); break;
		case ACTION_PUSH_TRANSFORM:
			printf("ACTION_PUSH_TRANSFORM\n"); break;
		case ACTION_POP_TRANSFORM:
			printf("ACTION_POP_TRANSFORM\n"); break;
		case ACTION_RESET_TRANSFORM:
			printf("ACTION_RESET_TRANSFORM\n"); break;
		}
	}

	printf("STOP\n");

#endif

	_shader.bind();
	while (!_renderQueue.empty())
	{
		RenderAction* action = _renderQueue.front();
		switch (action->actionID)
		{
		case ACTION_RENDER_TRIANGLES:
		{
			Renderable* renderable = (Renderable*)action->data;
			renderable->getMesh().getVAO()->bind();
			renderable->getMesh().getIBO()->bind();
			renderable->getMesh().getTBO()->bind();

			_lastTransform = &_transformStack.back();
			_shader.setUniform("model", renderable->getTransform() * *_lastTransform);
			_shader.setUniform("projection", _camera.getProjection());
			_shader.setUniform("view", _camera.getView());

			glDrawElements(GL_TRIANGLES, renderable->getMesh().getIBO()->getSize(), GL_UNSIGNED_SHORT, nullptr);

			renderable->getMesh().getTBO()->unbind();
			renderable->getMesh().getIBO()->unbind();
			renderable->getMesh().getVAO()->unbind();
			break;
		}
		case ACTION_RENDER_LINES:
		{
			Renderable* renderable = (Renderable*)action->data;
			renderable->getMesh().getVAO()->bind();
			renderable->getMesh().getIBO()->bind();
			renderable->getMesh().getTBO()->bind();

			_lastTransform = &_transformStack.back();
			_shader.setUniform("model", renderable->getTransform() * *_lastTransform);
			_shader.setUniform("projection", _camera.getProjection());
			_shader.setUniform("view", _camera.getView());

			glDrawElements(GL_LINES, renderable->getMesh().getIBO()->getSize(), GL_UNSIGNED_SHORT, nullptr);

			renderable->getMesh().getTBO()->unbind();
			renderable->getMesh().getIBO()->unbind();
			renderable->getMesh().getVAO()->unbind();
			break;
		}
		case ACTION_PUSH_TRANSFORM:
		{
			pushTransform(*((Matrix4f*)(action->data)), false);
			break;
		}
		case ACTION_POP_TRANSFORM:
		{
			popTransform();
			break;
		}
		default:
			break;
		}
		_renderQueue.pop_front();
	}
	_shader.unbind();
	_transformStack.clear();
	_transformStack.push_back(Matrix4f::Identity()); // SLOW!
}

void BasicRenderer::submit(Renderable* renderable)
{
	RenderAction* action = new RenderAction(ACTION_RENDER_TRIANGLES, renderable);
	_renderQueue.push_back(action);
}

void BasicRenderer::push(Matrix4f& transform)
{
	RenderAction* action = new RenderAction(ACTION_PUSH_TRANSFORM, &transform);
	_renderQueue.push_back(action);
}

void BasicRenderer::pop()
{
	RenderAction* action = new RenderAction(ACTION_POP_TRANSFORM, nullptr);
	_renderQueue.push_back(action);
}

void BasicRenderer::pushTransform(const Matrix4f& transform, bool override)
{
	if (override) _transformStack.push_back(transform);
	else _transformStack.push_back(_transformStack.back() * transform);
	_lastTransform = &_transformStack.back();
}

void BasicRenderer::popTransform()
{
	if(_transformStack.size() > 1)
		_transformStack.pop_back();
	_lastTransform = &_transformStack.back();
}

/* BATCH RENDERER */

BatchRenderer::BatchRenderer(Shader& shader, Camera& camera, Mesh* batchMesh) : BaseRenderer(shader, camera), _mesh(*batchMesh)
{
	constructBuffer(*batchMesh);
}

BatchRenderer::~BatchRenderer()
{
	delete _ibo;
	glDeleteBuffers(1, &_vbo);
}

void BatchRenderer::submit(Renderable* renderable)
{
	Vertex* buffer = (Vertex*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void BatchRenderer::flush()
{

}

void BatchRenderer::constructBuffer(Mesh& mesh)
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	const GLsizei vertexCount = mesh.getVBO()->getSize();
	const GLsizei indexCount = mesh.getIBO()->getSize();

	// TODO: Modify *4* to be the num of vertices!!! (for 3D) / Add functionality
	glBufferData(GL_ARRAY_BUFFER, MAX_VERTICES * VERTEX_SIZE * vertexCount, nullptr, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(SHADER_VERTEX_LOCATION, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)nullptr);
	glVertexAttribPointer(SHADER_COLOR_LOCATION, 4, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)(offsetof(Vertex, Vertex::color)));
	glEnableVertexAttribArray(SHADER_VERTEX_LOCATION);
	glEnableVertexAttribArray(SHADER_COLOR_LOCATION);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint offset = 0;
	GLushort* indices = new GLushort[indexCount * MAX_VERTICES];

	for (int i = 0; i < indexCount * MAX_VERTICES; i += indexCount)
	{
		indices[i + 0] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;

		indices[i + 3] = offset + 2;
		indices[i + 4] = offset + 1;
		indices[i + 5] = offset + 0;

		offset += vertexCount;
	}

	_ibo = new Buffer(indices, indexCount);

	glBindVertexArray(0);

	delete indices;
}