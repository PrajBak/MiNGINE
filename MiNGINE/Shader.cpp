#include"Shader.h"

void checkCompileErrors(const std::string str, GLuint shader);

Shader::Shader(const char* vertexShader, const char* fragmentShader) {
	
	std::ifstream f1(vertexShader, std::ios::in);
	std::ifstream f2(fragmentShader, std::ios::out);
	
	if (!f1.good()) {
		std::cout << "[ERROR] : Vertex Shader File Path" << std::endl;
		return;
	}
	if (!f2.good()) {
		std::cout << "[ERROR] : Fragment Shader File Path" << std::endl;
		return;
	}

	f1.seekg(std::ios::end);
	int size1 = f1.tellg();
	f1.seekg(std::ios::beg);

	f2.seekg(std::ios::end);
	int size2 = f2.tellg();
	f2.seekg(std::ios::beg);

	char* vscode = new char[size1+1];
	char* fscode = new char[size2+1];

	int i = 0;
	for (char c = f1.get(); f1.good(); c = f1.get()) {
		vscode[i++] = c;
	}
	vscode[i] = 0;								//Null terminator

	int j = 0;
	for (char c = f2.get(); f2.good(); c = f2.get()) {
		fscode[j++] = c;
	}
	fscode[j] = 0;								//Null terminator
	f1.close();
	f2.close();

	GLuint vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vscode, NULL);
	glCompileShader(vertex);
	checkCompileErrors("VERTEX", vertex);

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fscode, NULL);
	glCompileShader(fragment);
	checkCompileErrors("FRAGMENT", fragment);

	shaderID= glCreateProgram();
	glAttachShader(shaderID, vertex);
	glAttachShader(shaderID, fragment);
	glLinkProgram(shaderID);
	checkCompileErrors("PROGRAM", shaderID);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	delete[] vscode;
	delete[] fscode;
}

void Shader::useShader() {
	glUseProgram(this->shaderID);
}

void checkCompileErrors(const std::string str, GLuint shader) {

	GLint success;
	GLchar infoLog[1024];
	if (str != "PROGRAM" || str != "Program") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << str << " : [ERROR] : Shader Compilation : " << infoLog << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << str << "[ERROR] : Program Compilation : " << infoLog << std::endl;
		}
	}
}