#pragma once

#include"GL\glew.h"
#include"GLFW\glfw3.h"

class IndexBuffer {
private:
	GLuint ibId;
	GLuint count;

public:
	IndexBuffer(GLfloat* _data, GLuint _count);
	void bind() const;
	void unbind() const;
};