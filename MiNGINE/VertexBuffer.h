#pragma once

#include"GL\glew.h"
#include"GLFW\glfw3.h"

class VertexBuffer {
private:

	GLuint vbId;
	GLuint componentCount;
	
public:
	VertexBuffer(GLfloat* _data, int _count, GLuint _componentCount);
	void bind() const;
	void unbind() const;

	GLuint getComponentCount() const;
};