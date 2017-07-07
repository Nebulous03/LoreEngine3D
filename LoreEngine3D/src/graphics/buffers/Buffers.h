#pragma once
#include <GL/glew.h>
#include <vector>

class Buffer
{
private:

	GLuint	_bufferID;
	GLuint	_vectorSize;
	GLuint	_size;
	bool	_isIndex;

public:

	Buffer(GLfloat* data, GLsizei size, GLuint _vectorSize);
	Buffer(GLushort* data, GLsizei size);
	~Buffer();

	void bind() const;
	void unbind() const;

	const GLuint getVectorSize() const;
	const GLuint getSize() const;

	bool isIndex() const;
};

class VertexArray
{
private:

	GLuint _arrayID;
	std::vector<Buffer*> _buffers;

public:

	VertexArray();
	~VertexArray();

	void attach(Buffer* buffer, GLuint location);

	void bind();
	void unbind();
};