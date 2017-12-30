#include"VertexArrayBuffer.h"

VertexArrayBuffer::VertexArrayBuffer() {
	glGenVertexArrays(1, &vabId);
}

void VertexArrayBuffer::addVertexBuffer(VertexBuffer* _vbo, GLuint index) {
	bind();
	_vbo->bind();
	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, _vbo->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);
	_vbo->unbind();
	unbind();
}

void VertexArrayBuffer::bind() const {
	glBindVertexArray(vabId);
}

void VertexArrayBuffer::unbind() const {
	glBindVertexArray(0);
}