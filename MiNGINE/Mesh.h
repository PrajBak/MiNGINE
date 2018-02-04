#pragma once
#include"GL\glew.h"
#include"GLFW\glfw3.h"
#include"IndexBuffer.h"
#include"VertexBuffer.h"
#include"VertexArrayBuffer.h"
#include<vector>

class Mesh {
	std::vector<float> vertexCords;
	std::vector<float> colorCords;
	std::vector<float> texCords;
	std::vector<unsigned int> indices;

	VertexArrayBuffer* vao;
	IndexBuffer* ibo;

public:
	Mesh(std::vector<float>& _vertexCords, std::vector<float>& _colorCords, std::vector<float> _texCords, std::vector<unsigned int>& _indices);
	void addMesh();
	void drawMesh(bool how);
	void endMesh();
};