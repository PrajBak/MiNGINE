#include"Camera.h"

GLfloat Camera::yaw = -90.f;
GLfloat Camera::pitch = 0.0f;
float Camera::lastX = 250.0f;
float Camera::lastY = 250.0f;
float Camera::fov = 45.0f;
bool Camera::firstMouse = true;

Camera::Camera(Window* window, glm::vec3& _pos, float _fov, float _aspectRatio, float zNear, float zFar) {
	Input i(window);
	in = i;
	Camera::fov = _fov;
	far = zFar;
	near = zNear;
	aspectRatio = _aspectRatio;
	perspective = glm::perspective(Camera::fov, aspectRatio, near, far);
	glfwSetCursorPosCallback(window->_window, mousecallback);
	glfwSetScrollCallback(window->_window, scrollcallback);
	position = _pos;
	forward = glm::vec3(0.0f, 0.0f, -1.0f);
	camSpeed = 0.005f;
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

	perspective = glm::perspective(glm::radians(Camera::fov), aspectRatio, near, far);

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

void scrollcallback(GLFWwindow* window, double xOffset, double yOffset) {

	if (Camera::fov >= 1.0f && Camera::fov <= 45.0f)
		Camera::fov -= yOffset*2.0f;
	if (Camera::fov <= 1.0f)
		Camera::fov = 1.0f;
	if (Camera::fov >= 45.0f)
		Camera::fov = 45.0f;
}