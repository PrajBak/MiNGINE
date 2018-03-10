#include"Camera.h"

Camera::Camera(glm::vec3& _pos, float fov, float aspectRatio, float zNear, float zFar) {
	position = _pos;
	perspective = glm::perspective(fov, aspectRatio, zNear, zFar);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	forward = glm::vec3(0.0f, 0.0f, 1.0f);
}

glm::vec3& Camera::getPosition() {
	return position;
}

glm::mat4 Camera::getViewPersepective() {
	return (perspective*glm::lookAt(position, position+forward, up));
}