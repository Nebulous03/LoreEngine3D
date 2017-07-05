#include "Buffers.h"
#include "../../math/Math.h"

/* BUFFER */

Buffer::Buffer(GLfloat* data, GLsizei size, GLuint componentCount) : _componentCount(componentCount)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
}

void Buffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

inline GLuint Buffer::getComponentCount() const
{
	return _componentCount;
}

/* INDEX BUFFER */

IndexBuffer::IndexBuffer(GLushort* data, GLsizei count) : _count(count)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLushort), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
}

void IndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

inline GLuint IndexBuffer::getCount() const
{
	return _count;
}

/* VERTEX ARRAY */

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &_arrayID);
}

VertexArray::~VertexArray()
{
	for (uint i = 0; i < _buffers.size(); i++) delete _buffers[i];
}

void VertexArray::add(Buffer* buffer, GLuint location)
{
	bind();
	buffer->bind();
	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

	buffer->unbind();
	unbind();
}

void VertexArray::bind()
{
	glBindVertexArray(_arrayID);
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
}