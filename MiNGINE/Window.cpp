#include"Window.h"
//getframebuffersize added and setaspectratio also added, moved setwindowsizecallback from window current to update.
void windowsizecallback(GLFWwindow* window, int width, int height);

Window::Window(int _width, int _height, const char* _name)
	: width(_width), height(_height), name(_name), running(false)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	_window = glfwCreateWindow(width, height, name, GLFW_FALSE, GLFW_FALSE);
}

void Window::windowCurrent() {

	if (!_window)
		std::cout << "[ERROR] : Window not created!!" << std::endl;

	else {
		glfwMakeContextCurrent(_window);
		running = true;
	}
	glfwSetFramebufferSizeCallback(_window, windowsizecallback);
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Window::update() {
	glfwSwapBuffers(_window);
	glfwPollEvents();
}

bool Window::isRunning() {
	if (glfwWindowShouldClose(_window) || glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		running = false;
	return running;
}

void Window::setRunning(bool _running) {
	running = _running;
}

void windowsizecallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}