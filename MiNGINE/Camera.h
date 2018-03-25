#pragma once
#include"GL\glew.h"
#include"GLFW\glfw3.h"
#include"glm\glm.hpp"
#include"glm\gtx\transform.hpp"
#include"glm\gtc\type_ptr.hpp"
#include"Window.h"
#include"Input.h"


class Camera {
private:
	Input in;
	glm::vec3 up;
	glm::vec3 forward;
	glm::vec3 position;
	glm::vec3 right;
	glm::mat4 perspective;
	float camSpeed;
	static GLfloat yaw;
	static GLfloat pitch;
	static float lastX;
	static float lastY;
	static bool firstMouse;
public:
	Camera(Window* window, glm::vec3& pos, float fov, float aspectRatio, float zNear, float zFar);
	glm::vec3& getPosition();
	glm::mat4 getViewPersepective();
	void update();
	friend void mousecallback(GLFWwindow* window, double xpos, double ypos);
};