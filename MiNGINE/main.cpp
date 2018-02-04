#include<iostream>
#include"GL\glew.h"
#include"GLFW\glfw3.h"
#include"Texture.h"
#include"Shader.h"
#include"Transform.h"
#include"VertexBuffer.h"
#include"VertexArrayBuffer.h"
#include"IndexBuffer.h"
#include"Window.h"
#include"Mesh.h"
#include<vector>

int main() {

	if (!glfwInit())
		std::cout << "[ERROR] : GLFW INITIALISATION" << std::endl;

	Window* window;
	window = new Window(500, 500, "MiNGINE");
	window->windowCurrent();

	if (glewInit()!= GLEW_OK)
		std::cout << "[ERROR] : GLEW INITIALISATION!!" << std::endl;

	const char* gCard;
	gCard = (const char*)glGetString(GL_RENDERER);
	std::cout << gCard << std::endl;

	glEnable(GL_DEPTH_TEST);

	float vertices[] = {
		-0.5f, 0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		 0.5f,-0.5f,-0.5f,
		 0.5f, 0.5f,-0.5f,

		-0.5f, 0.5f, 0.5f,
		-0.5f,-0.5f, 0.5f,
		 0.5f,-0.5f, 0.5f,
		 0.5f, 0.5f, 0.5f,

		 0.5f, 0.5f, 0.5f,
		 0.5f,-0.5f, 0.5f,
		 0.5f,-0.5f,-0.5f,
		 0.5f, 0.5f,-0.5f,

		-0.5f, 0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,

		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f,-0.5f,
		 0.5f, 0.5f,-0.5f,
		 0.5f, 0.5f, 0.5f,

		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f, 0.5f,
		 0.5f,-0.5f, 0.5f,
		 0.5f,-0.5f,-0.5f

	};

	float color[] = {
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	};

	float textureCord[] = {
		0, 1,
		0, 0,
		1, 0,
		1, 1,

		0, 1,
		0, 0,
		1, 0,
		1, 1,

		0, 1,
		0, 0,
		1, 0,
		1, 1,

		0, 1,
		0, 0,
		1, 0,
		1, 1,

		0, 1,
		0, 0,
		1, 0,
		1, 1,

		0, 1,
		0, 0,
		1, 0,
		1, 1
	};

	int sq = 0;
	std::vector<unsigned int> indices;

	for (int i = 0; i < sizeof(vertices) / (sizeof(float) * 12); i++) {
		indices.push_back(sq + 0);
		indices.push_back(sq + 1);
		indices.push_back(sq + 2);
		 	 
		indices.push_back(sq + 2);
		indices.push_back(sq + 3);
		indices.push_back(sq + 0);
		sq += 4;
	}

	/*unsigned int indices[] = {
		0,1,2,
		2,3,0,

		2,6,7,
		7,3,2,

		4,5,6,
		6,7,4,

		5,1,4,
		4,8,5,

		5,6,2,
		2,1,5,

		8,7,3,
		3,4,8
	};
	*/
	///Whenever you want to change vertices you dont have to fiddle with this now XD.It handles the size.
	std::vector<float> vvertices(vertices, vertices+sizeof(vertices)/sizeof(float));
	std::vector<float> vcolor(color, color + sizeof(color) / sizeof(float));
	std::vector<float> vtex(textureCord, textureCord + sizeof(textureCord) / sizeof(float));

	Mesh mesh(vvertices, vcolor, vtex, indices);
	mesh.addMesh();

	Shader ourShader("./vertexShader.vs", "./fragmentShader.fs");
	ourShader.useShader();

	Transform tran;

	Texture texture1;
	Texture texture2;
	texture1.loadTexture("./awesomeface.png", ourShader);
	texture2.loadTexture("./container.jpg", ourShader);

	while(window->isRunning()) {
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		texture1.bind();
		texture2.bind();
		tran.getPos() = glm::vec3(0.0f, 0.0f, 0.0f);
		tran.getRot().y += glm::radians(0.05f);
		tran.getRot().x += glm::radians(0.05f);
		tran.setTransformMatrix(ourShader);
		mesh.drawMesh(true);
		window->update();
	
	}
	mesh.endMesh();
	texture1.unbind();
	texture2.unbind();

	return 0;
}