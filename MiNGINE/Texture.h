#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"stb_image.h"
#include<iostream>
#include<stdio.h>
#include"GL\glew.h"
#include"GLFW\glfw3.h"

class Texture {
private:
	GLuint texId;
	int width, height;
	int nrChannels;
	unsigned char* data;
public:
	Texture();
	void loadTexture(const char* imagePath);
	void bind();
	void unbind();
	//void loadTextureBMP(const char* imagePath);
};