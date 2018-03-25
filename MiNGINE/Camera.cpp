#include"Camera.h"

GLfloat Camera::yaw = -90.f;
GLfloat Camera::pitch = 0.0f;
float Camera::lastX = 250.0f;
float Camera::lastY = 250.0f;
bool Camera::firstMouse = true;

Camera::Camera(Window* window, glm::vec3& _pos, float fov, float aspectRatio, float zNear, float zFar) {
	Input i(window);
	in = i;
	perspective = glm::perspective(fov, aspectRatio, zNear, zFar);
	glfwSetCursorPosCallback(window->_window, mousecallback);
	position = _pos;
	forward = glm::vec3(0.0f, 5.0f, -1.0f);
	camSpeed = 0.008f;
}

glm::vec3& Camera::getPosition() {
	return position;
}

glm::mat4 Camera::getViewPersepective() {
	return (perspective*glm::lookAt(position, forward + position, up));
}

void Camera::update() {
	if (in.isKeyPressed(GLFW_KEY_W)) {
		position += forward * camSpeed;
	}
	if (in.isKeyPressed(GLFW_KEY_S)) {
		position -= forward * camSpeed;
	}
	if (in.isKeyPressed(GLFW_KEY_D)) {
		position -= right * camSpeed;
	}
	if (in.isKeyPressed(GLFW_KEY_A)) {
		position += right * camSpeed;
	}

	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward = glm::normalize(front);
	glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);
	right = glm::normalize(glm::cross(_up, forward));
	up = glm::normalize(glm::cross(forward, right));
}

void mousecallback(GLFWwindow* window, double xpos, double ypos) {

	if (Camera::firstMouse) {
		Camera::lastX = xpos;
		Camera::lastY = ypos;
		Camera::firstMouse = false;
	}

	float xOffset = xpos - Camera::lastX;
	float yOffset = Camera::lastY - ypos;

	Camera::lastX = xpos;
	Camera::lastY = ypos;

	xOffset *= 0.05;
	yOffset *= 0.05;

	Camera::yaw += xOffset;
	Camera::pitch += yOffset;

	if (Camera::pitch > 89.0f)
		Camera::pitch = 89.0f;
	if (Camera::pitch < -89.0f)
		Camera::pitch = -89.0f;
}