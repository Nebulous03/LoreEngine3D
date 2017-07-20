#pragma once
#include "Renderable.h"
#include "Camera.h"
#include <deque>

#define MAX_VERTICES	65535
#define VERTEX_SIZE		sizeof(Vertex)

#define SHADER_VERTEX_LOCATION	0
#define SHADER_COLOR_LOCATION	1

#define ACTION_NONE				0
#define ACTION_RENDER_TRIANGLES	1
#define ACTION_RENDER_LINES		2
#define ACTION_PUSH_TRANSFROM	3
#define ACTION_POP_TRANSFORM	4
#define ACTION_RESET_TRANSFORM	5

struct RenderAction
{
	uint8_t actionID = ACTION_NONE;
	void* data = nullptr;
};

class BaseRenderer
{
protected:
	Camera& _camera;
	Shader& _shader;
public:
	BaseRenderer(Shader& shader, Camera& camera);
	virtual ~BaseRenderer();
	virtual void begin();
	virtual void end();
	virtual void push(Renderable* renderable) = 0;
	virtual void flush() = 0;
};

class BasicRenderer : public BaseRenderer
{
protected:

	std::deque<Renderable*> _renderQueue;
	std::vector<Matrix4f> _transformStack;
	Matrix4f* _lastTransform;

public:
	BasicRenderer(Shader& shader, Camera& camera);
	void push(Renderable* renderable) override;
	void flush() override;
	void pushTransform(const Matrix4f& transform, bool override = false);
	void popTransform();
};

class BatchRenderer : public BaseRenderer
{
protected:

	GLuint _vao;
	Buffer* _ibo;
	GLuint _vbo;

	Mesh& _mesh;

public:

	BatchRenderer(Shader& shader, Camera& camera, Mesh* batchMesh);
	~BatchRenderer();

	void constructBuffer(Mesh& batchMesh);

	void add(Renderable& renderable);

	void push(Renderable* renderable) override;
	void flush() override;

};