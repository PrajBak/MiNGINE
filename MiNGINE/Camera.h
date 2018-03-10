#pragma once
#include"glm\glm.hpp"
#include"glm\gtx\transform.hpp"
#include"glm\gtc\type_ptr.hpp"


class Camera {
private:
	glm::vec3 up;
	glm::vec3 forward;
	glm::vec3 position;
	glm::mat4 perspective;
public:
	Camera(glm::vec3& pos, float fov, float aspectRatio, float zNear, float zFar);
	glm::vec3& getPosition();
	glm::mat4 getViewPersepective();
};