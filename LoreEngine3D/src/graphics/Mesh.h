#pragma once
#include "buffers\Buffers.h"

struct Index
{
	short vi;
	short ti;
	short ni;

	Index();
	Index(short vertex, short texCoord, short normal);
};

class Mesh
{
protected:

	VertexArray* _vao;

	Buffer*	_vbo;
	Buffer*	_ibo;
	Buffer*	_cbo;
	Buffer*	_tbo;

	Mesh() = default;

public:

	Mesh
	(
		GLfloat* vertices, GLsizei vertexCount, 
		GLushort* indices, GLsizei indicesCount, 
		GLfloat* colors = nullptr, GLsizei colorCount = 0, 
		GLfloat* texCoords = nullptr, GLsizei texCoordCount = 0
	);

	~Mesh();

	VertexArray* getVAO() const;
	Buffer* getVBO() const;
	Buffer* getIBO() const;
	Buffer* getCBO() const;
	Buffer* getTBO() const;

	static Mesh Plane
	(
		GLfloat xSize, GLfloat ySize,
		GLfloat* colors = nullptr, GLsizei colorCount = 0,
		GLfloat* texCoords = nullptr, GLsizei texCoordCount = 0
	);


};