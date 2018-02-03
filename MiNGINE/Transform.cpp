#include"Transform.h"

Transform::Transform(const glm::vec3 pos, const glm::vec3 rot, const glm::vec3 scale) 
	:m_pos(pos), m_rot(rot), m_scale(scale)
	{}

glm::vec3& Transform::getPos() {
	return m_pos;
}

glm::vec3& Transform::getRot() {
	return m_rot;
}

glm::vec3& Transform::getScale() {
	return m_scale;
}

glm::mat4 Transform::getTransformMatrix() {
	glm::mat4 transMatrix = glm::translate(m_pos);
	glm::mat4 rotateX = glm::rotate(m_rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotateY = glm::rotate(m_rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotateZ = glm::rotate(m_rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 scaleMatrix = glm::scale(m_scale);

	glm::mat4 rotateMatrix = rotateZ * rotateY * rotateX;

	return glm::mat4(transMatrix * rotateMatrix * scaleMatrix);
}

void Transform::setTransformMatrix(Shader& ourShader) {
	glm::mat4 modelMatrix = getTransformMatrix();
	ourShader.setMat4("transform", modelMatrix);
}