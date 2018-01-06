#include<iostream>
#include"GL\glew.h"
#include"GLFW\glfw3.h"
#include"Shader.h"
#include"VertexBuffer.h"
#include"VertexArrayBuffer.h"
#include"IndexBuffer.h"
#include"Window.h"


int main() {

	if (!glfwInit())
		std::cout << "[ERROR] : GLFW INITIALISATION" << std::endl;

	Window* window;
	window = new Window(500, 500, "MiNGINE");
	window->windowCurrent();

	if (glewInit()!= GLEW_OK)
		std::cout << "[ERROR] : GLEW INITIALISATION!!" << std::endl;

	float vertices[] = {
		 0.5f, 0.5f, 0.0f,	
		 0.5f,-0.5f, 0.0f,	
		-0.5f,-0.5f, 0.0f,	
		-0.5f, 0.5f, 0.0f
	};

	float color[] = {
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f
	};

	unsigned int indices[] = {
		3, 0, 1,
		1, 2, 3
	};

	VertexArrayBuffer vao;
	VertexBuffer* vbo = new VertexBuffer(vertices, 3 * 4, 3);
	VertexBuffer* cbo = new VertexBuffer(color, 3 * 4, 3);
	IndexBuffer ibo(indices, 6);

	vao.addVertexBuffer(vbo, 0);
	vao.addVertexBuffer(cbo, 1);
	
	Shader ourShader("./vertexShader.vs", "./fragmentShader.fs");
	ourShader.useShader();

	while(window->isRunning()) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		vao.bind();
		ibo.bind();

		glDrawElements(GL_POINTS, ibo.getCount(), GL_UNSIGNED_INT, indices);
		//glDrawArrays(GL_TRIANGLES, 0, 4);
		window->update();
	}

	vao.unbind();
	vbo->unbind();
	cbo->unbind();
	ibo.unbind();

	return 0;
}