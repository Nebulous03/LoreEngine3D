#pragma once
#include "Renderable.h"
#include "Camera.h"
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

class BaseRenderer
{
protected:
	Camera* _camera;
	Shader* _shader;
public:
	BaseRenderer(Shader* shader, Camera* camera);
	virtual ~BaseRenderer();
	virtual void push(Renderable* renderable) = 0;
	virtual void flush() = 0;
};

class BasicRenderer : public BaseRenderer
{
protected:

	std::deque<Renderable*> _renderables;

public:
	BasicRenderer(Shader* shader, Camera* camera);
	void push(Renderable* renderable) override;
	void flush() override;

};

class BatchRenderer : public BaseRenderer
{
protected:

	GLuint _vao;
	Buffer* _ibo;
	GLuint _vbo;

	Mesh& _mesh;

public:

	BatchRenderer(Shader* shader, Camera* camera, Mesh* batchMesh);
	~BatchRenderer();

	void constructBuffer(Mesh& batchMesh);

	void add(Renderable& renderable);

	void push(Renderable* renderable) override;
	void flush() override;

};