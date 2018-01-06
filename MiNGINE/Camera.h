#pragma once
#include"glm\glm.hpp"
#include"glm\gtc\matrix_transform.hpp"

class Camera {
private:
	glm::vec3 pos;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;


};