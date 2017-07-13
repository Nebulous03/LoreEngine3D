#include "Renderer.h"
#include "buffers\Buffers.h"
#include <cstdio>
#include <iostream>

/* BASIC RENDERER */

BaseRenderer::BaseRenderer(Shader& shader, Camera& camera) : _shader(shader), _camera(camera) {}

BasicRenderer::BasicRenderer(Shader& shader, Camera& camera) : BaseRenderer(shader, camera) {}

BaseRenderer::~BaseRenderer() {}

void BaseRenderer::begin() {}

void BaseRenderer::end() {}

void BasicRenderer::push(Renderable* renderable)
{
	_renderables.push_back(renderable);
}

void BasicRenderer::flush()
{
	_shader.bind();
	while (!_renderables.empty())
	{
		Renderable* renderable = _renderables.front();
		renderable->getMesh().getVAO()->bind();
		renderable->getMesh().getIBO()->bind();

		_shader.setUniform("model", renderable->getTranslation());
		_shader.setUniform("projection", _camera.getProjection());
		_shader.setUniform("view", _camera.getView());

		glDrawElements(GL_TRIANGLES, renderable->getMesh().getIBO()->getSize(), GL_UNSIGNED_SHORT, nullptr);

		renderable->getMesh().getIBO()->unbind();
		renderable->getMesh().getVAO()->unbind();

		_renderables.pop_front();
	}
	_shader.unbind();
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

void BatchRenderer::push(Renderable* renderable)
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