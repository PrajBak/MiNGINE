#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(GLfloat * _data, GLuint _count)
	:count(_count)
{
	glGenBuffers(1, &ibId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibId);
	glBufferData(ibId, _count * sizeof(GLfloat), _data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::bind() const{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibId);
}

void IndexBuffer::unbind() const{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}