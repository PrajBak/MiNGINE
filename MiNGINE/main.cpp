#include<iostream>
#include"GL\glew.h"
#include"GLFW\glfw3.h"
#include"Window.h"


int main() {

	if (!glfwInit())
		std::cout << "[ERROR] : GLFW INITIALISATION" << std::endl;

	Window* window;
	window = new Window(500, 500, "MiNGINE");
	window->windowCurrent();

	if (glewInit()!= GLEW_OK)
		std::cout << "[ERROR] : GLEW INITIALISATION!!" << std::endl;

	while(window->isRunning()) {
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0f, 0.1f, 0.1f, 0.0f);

		window->update();
	}

	return 0;
}