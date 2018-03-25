#include"Input.h"

Input::Input(Window* window) 
	:mWindow(window)
{
}

Input::Input(Input& input) {
	*this = input;
}

bool Input::isKeyPressed(int key) {
	int action = GLFW_PRESS;
	if (glfwGetKey((mWindow->_window), key))
		action = GLFW_RELEASE;
	if (action == GLFW_RELEASE) {
		action = GLFW_PRESS;
		return true;
	}
	return false;
}

bool Input::isMouseButtonPressed(int button) {
	if (glfwGetMouseButton((mWindow->_window), button) == GLFW_RELEASE)
		return true;
}
