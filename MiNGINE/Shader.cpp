#include"Shader.h"

void checkCompileErrors(const std::string str, GLuint shader);

Shader::Shader(const char* vertexShader, const char* fragmentShader) {
	
	std::ifstream f1(vertexShader, std::ios::in);
	std::ifstream f2(fragmentShader, std::ios::in);
	
	if (!f1.good()) {
		std::cout << "[ERROR] : Vertex Shader File Path" << std::endl;
		return;
	}
	if (!f2.good()) {
		std::cout << "[ERROR] : Fragment Shader File Path" << std::endl;
		return;
	}

	f1.seekg(0, std::ios::end);
	int size1 = f1.tellg();
	f1.seekg(0, std::ios::beg);

	f2.seekg(0, std::ios::end);
	int size2 = f2.tellg();
	f2.seekg(0, std::ios::beg);

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

void Shader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value); 
}

void Shader::setVec2(const std::string &name, const glm::vec2 &value) const
{ 
    glUniform2fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]); 
}

void Shader::setVec2(const std::string &name, float x, float y) const
{ 
    glUniform2f(glGetUniformLocation(shaderID, name.c_str()), x, y); 
}

void Shader::setVec3(const std::string &name, const glm::vec3 &value) const
{ 
    glUniform3fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]); 
}

void Shader::setVec3(const std::string &name, float x, float y, float z) const
{ 
    glUniform3f(glGetUniformLocation(shaderID, name.c_str()), x, y, z); 
}

void Shader::setVec4(const std::string &name, const glm::vec4 &value) const
{ 
    glUniform4fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]); 
}

void Shader::setVec4(const std::string &name, float x, float y, float z, float w) const  
{ 
	glUniform4f(glGetUniformLocation(shaderID, name.c_str()), x, y, z, w); 
}

void Shader::setMat2(const std::string &name, const glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
    
void Shader::setMat3(const std::string &name, const glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const std::string &name, const glm::mat4 &mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
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