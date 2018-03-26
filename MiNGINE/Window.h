#pragma once
#include<iostream>
#include"GL\glew.h"
#include"GLFW\glfw3.h"

class Window{
private:
	int width, height;
	const char* name;
	bool running;

public:
	GLFWwindow* _window;
	Window(int _width, int _height, const char* _name);
	void update();
	bool isRunning();
	void windowCurrent();
	void setRunning(bool _running);
	float getAspectRatio();
};