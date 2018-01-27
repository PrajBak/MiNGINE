#pragma once
#include"glm\glm.hpp"
#include"glm\gtx\transform.hpp"
#include"glm\gtc\type_ptr.hpp"

class Transform {
	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_scale;

public:
	Transform(const glm::vec3 pos = glm::vec3(0, 0, 0), const glm::vec3 rot = glm::vec3(0, 0, 0), const glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f));
	glm::mat4 getTransformMatrix();
	glm::vec3& getPos();
	glm::vec3& getRot();
	glm::vec3& getScale();
};