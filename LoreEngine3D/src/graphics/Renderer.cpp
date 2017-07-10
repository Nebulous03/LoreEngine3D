#include "Renderer.h"
#include "buffers\Buffers.h"
#include <cstdio>
#include <iostream>

/* BASIC RENDERER */

RendererBase::RendererBase(Camera& camera) : _camera(camera) {}

BasicRenderer::BasicRenderer(Camera& camera) : RendererBase(camera) {}

void BasicRenderer::push(Renderable& renderable)
{
	_renderables.push_back(&renderable);
}

void BasicRenderer::flush()
{
	while (!_renderables.empty())
	{
		const Renderable& renderable = *_renderables.front();
		renderable.getMesh()->getVAO()->bind();
		renderable.getMesh()->getIBO()->bind();

		renderable.getShader()->setUniform("model", *(renderable.getTranslation()));
		renderable.getShader()->setUniform("projection", _camera.getProjection());
		renderable.getShader()->setUniform("view", _camera.getView());

		glDrawElements(GL_TRIANGLES, renderable.getMesh()->getIBO()->getSize(), GL_UNSIGNED_SHORT, nullptr);

		renderable.getMesh()->getIBO()->unbind();
		renderable.getMesh()->getVAO()->unbind();

		_renderables.pop_front();
	}
}

/* BATCH RENDERER */

BatchRenderer::BatchRenderer(Camera& camera, Mesh& batchMesh) : RendererBase(camera), _mesh(batchMesh)
{
	constructBuffer(batchMesh);
}

BatchRenderer::~BatchRenderer()
{
	delete _ibo;
	glDeleteBuffers(1, &_vbo);
}

void BatchRenderer::push(Renderable& renderable)
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