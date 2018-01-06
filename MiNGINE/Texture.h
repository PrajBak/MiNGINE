#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include"GL\glew.h"
#include"GLFW\glfw3.h"

class Texture {
private:
	GLuint texId;
	unsigned int width, height;
	unsigned char* data;
public:
	Texture();
	void loadTexture(const char* imagePath);
	void bind();
	void unbind();
};