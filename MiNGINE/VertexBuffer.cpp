#include"VertexBuffer.h"

VertexBuffer::VertexBuffer(GLfloat* _data, int _count, GLuint _componentCount)
	: componentCount(_componentCount)
{
	glGenBuffers(1, &vbId);
	glBindBuffer(GL_ARRAY_BUFFER, vbId);
	glBufferData(GL_ARRAY_BUFFER, _count*sizeof(GLfloat), _data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::bind() const{
	glBindBuffer(GL_ARRAY_BUFFER, vbId);
}

void VertexBuffer::unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

GLuint VertexBuffer::getComponentCount() const{
	return componentCount;
}