#pragma once
#include "Renderable.h"
#include "Camera.h"
#include <deque>

#define MAX_VERTICES	65535
#define VERTEX_SIZE		sizeof(Vertex)

#define SHADER_VERTEX_LOCATION		0
#define SHADER_COLOR_LOCATION		1
#define SHADER_TEXCOORD_LOCATION	2
#define SHADER_NORMAL_LOCATION		3

#define ACTION_NONE					0
#define ACTION_RENDER_TRIANGLES		1
#define ACTION_RENDER_LINES			2
#define ACTION_PUSH_TRANSFORM		3
#define ACTION_POP_TRANSFORM		4
#define ACTION_RESET_TRANSFORM		5

struct Vertex
{
	Vector3f vertex;
	Vector3f color;
	Vector2f texCoord;
	Vector3f normal;
};

struct RenderAction
{
	uint8_t actionID = ACTION_NONE;
	void* data = nullptr;

	RenderAction(uint8_t actionID, void* data);
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
	virtual void submit(Renderable* renderable) = 0;
	virtual void flush() = 0;
};

class BasicRenderer : public BaseRenderer
{
protected:

	std::deque<RenderAction*> _renderQueue;
	std::vector<Matrix4f> _transformStack;
	Matrix4f* _lastTransform;

	void pushTransform(const Matrix4f& transform, bool override = false);
	void popTransform();

public:
	BasicRenderer(Shader& shader, Camera& camera);
	void submit(Renderable* renderable) override;
	void push(Matrix4f& transform);
	void pop();
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

	BatchRenderer(Shader& shader, Camera& camera, Mesh* batchMesh);
	~BatchRenderer();

	void constructBuffer(Mesh& batchMesh);

	void add(Renderable& renderable);

	void submit(Renderable* renderable) override;
	void flush() override;

};