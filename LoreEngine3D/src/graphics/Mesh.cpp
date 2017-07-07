#include "Mesh.h"
#include <iostream>

Mesh::Mesh	// TODO: Allow texCoords w/o setting colors
(
	GLfloat* vertices, GLsizei vertexCount,
	GLushort* indices, GLsizei indicesCount,
	GLfloat* colors, GLsizei colorCount,
	GLfloat* texCoords, GLsizei texCoordCount
) 
{
	_vao = new VertexArray();
	_vbo = new Buffer(vertices, vertexCount, 3);
	_ibo = new Buffer(indices, indicesCount);

	_vao->attach(_vbo, 0);

	if (colors != nullptr)
	{
		_cbo = new Buffer(colors, colorCount, 4);
		_vao->attach(_cbo, 1);
		std::cout << "COLORS ENABLED" << std::endl;
	}

	if (texCoords != nullptr)
	{
		_tbo = new Buffer(texCoords, texCoordCount, 3);
		_vao->attach(_cbo, 2);
	}

}

Mesh::~Mesh()
{
	delete _vao;
	delete _vbo;
	delete _ibo;
	delete _cbo;
	delete _tbo;
}

VertexArray* Mesh::getVAO() const
{
	return _vao;
}

Buffer* Mesh::getVBO() const
{
	return _vbo;
}

Buffer* Mesh::getIBO() const
{
	return _ibo;
}

Buffer* Mesh::getCBO() const
{
	return _cbo;
}

Buffer* Mesh::getTBO() const
{
	return _tbo;
}

Mesh Mesh::Plane
(
	GLfloat xSize, GLfloat ySize,
	GLfloat* colors, GLsizei colorCount,
	GLfloat* texCoords, GLsizei texCoordCount
)
{

	GLfloat vertices[] =
	{
		0,		0,		0,
		0,		ySize,  0,
		xSize,  ySize,  0,
		xSize,  0,		0,
	};

	GLushort indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	return Mesh(vertices, 12, indices, 6, colors, colorCount, texCoords, texCoordCount);
}