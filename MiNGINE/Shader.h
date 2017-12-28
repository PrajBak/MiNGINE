#pragma once
#include"GL\glew.h"
#include"GLFW\glfw3.h"
#include<fstream>
#include<iostream>
#include<string>

class Shader {
private:
	GLuint shaderID;
public:
	Shader(const char* vertexShader, const char* fragmentShader);
	void useShader();
};