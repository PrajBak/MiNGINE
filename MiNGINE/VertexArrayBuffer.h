#pragma once
#include"VertexBuffer.h"
#include"GL\glew.h"
#include"GLFW\glfw3.h"

class VertexArrayBuffer {
private:
	GLuint vabId;

public:
	VertexArrayBuffer();
	void addVertexBuffer(VertexBuffer* _vbo, GLuint index);
	void bind() const;
	void unbind() const;
};