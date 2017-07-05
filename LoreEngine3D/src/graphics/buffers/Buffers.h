#pragma once
#include <GL/glew.h>
#include <vector>

class Buffer
{
private:
	GLuint _bufferID;
	GLuint _componentCount;
public:

	Buffer(GLfloat* data, GLsizei size, GLuint componentCount);

	void bind() const;
	void unbind() const;

	inline GLuint getComponentCount() const;

};

class IndexBuffer
{
private:
	GLuint _bufferID;
	GLuint _count;
public:

	IndexBuffer(GLushort* data, GLsizei count);

	void bind() const;
	void unbind() const;

	inline GLuint getCount() const;

};

class VertexArray
{
private:
	GLuint _arrayID;
	std::vector<Buffer*> _buffers;
public:
	VertexArray();
	~VertexArray();
	void add(Buffer* buffer, GLuint index);

	void bind();
	void unbind();
};