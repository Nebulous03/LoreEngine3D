#pragma once
#include "Renderable.h"
#include <deque>

#define MAX_VERTICES	65535
#define VERTEX_SIZE		sizeof(Vertex)

#define SHADER_VERTEX_LOCATION	0
#define SHADER_COLOR_LOCATION	1

struct Vertex
{
	Vector3f vertex;
	Vector3f color;
};

class RendererBase
{
public:

	virtual void push(Renderable& renderable) = 0;
	virtual void flush() = 0;

};

class BasicRenderer : public RendererBase
{
protected:

	std::deque<Renderable*> _renderables;

public:

	void push(Renderable& renderable) override;
	void flush() override;

};

class BatchRenderer : public RendererBase
{
protected:

	GLuint _vao;
	Buffer* _ibo;
	GLuint _vbo;

	Mesh& _mesh;

public:

	BatchRenderer(Mesh& batchMesh);
	~BatchRenderer();

	void constructBuffer(Mesh& batchMesh);

	void add(Renderable& renderable);

	void push(Renderable& renderable) override;
	void flush() override;

};