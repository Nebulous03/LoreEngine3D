#include "Buffers.h"
#include "../../math/Math.h"

/* BUFFER */

Buffer::Buffer(GLfloat* data, GLsizei size, GLuint vectorSize) : _size(size), _vectorSize(vectorSize)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	_isIndex = false;
}

Buffer::Buffer(GLushort* data, GLsizei size) : _size(size)
{
	glGenBuffers(1, &_bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(GLushort), data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	_isIndex = true;
}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &_bufferID);
}

void Buffer::bind() const	// slow?
{
	if (_isIndex) glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
	else glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
}

void Buffer::unbind() const
{
	if (_isIndex) glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	else glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const GLuint Buffer::getVectorSize() const
{
	return _vectorSize;
}

const GLuint Buffer::getSize() const
{
	return _size;
}

bool Buffer::isIndex() const
{
	return _isIndex;
}

/* VERTEX ARRAY */

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &_arrayID);
}

VertexArray::~VertexArray()
{
	for (uint i = 0; i < _buffers.size(); i++) delete _buffers[i];
	glDeleteBuffers(1, &_arrayID);
}

void VertexArray::attach(Buffer* buffer, GLuint location)
{
	bind();
	buffer->bind();

	glEnableVertexAttribArray(location);
	glVertexAttribPointer(location, buffer->getVectorSize(), GL_FLOAT, GL_FALSE, 0, 0);

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