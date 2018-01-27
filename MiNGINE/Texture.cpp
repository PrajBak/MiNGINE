#include"Texture.h"

unsigned int Texture::noOfTex = 0;

Texture::Texture()
	: width(0), height(0), data(nullptr){}

void Texture::loadTexture(const char* imagePath, Shader& ourShader) {

	std::string texName("texture");

	stbi_set_flip_vertically_on_load(true);

	data = stbi_load(imagePath, &width, &height, &nrChannels, 0);

	if (!data) {
		std::cout << "[ERROR] : Not able to load the file" << std::endl;
		return;
	}
	currTex = noOfTex + 1;
	texName += std::to_string(currTex);
	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);

	if (nrChannels == 3)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	else if (nrChannels == 4)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	stbi_image_free(data);
	ourShader.useShader();
	ourShader.setInt(texName, currTex - 1);
	glBindTexture(GL_TEXTURE_2D, 0);
	noOfTex++;
}


/*void Texture::loadTextureBMP(const char* imagePath) {

	unsigned int dataPos;
	unsigned int imageSize;
	unsigned char header[54];

	FILE* tex = fopen(imagePath, "rb");
	if (!tex) {
		std::cout << "[ERROR] : Could not open texture" << std::endl;
		return;
	}

	if (fread(header, 1, 54, tex) != 54) {
		std::cout << "[ERROR] : Not a BMP file" << std::endl;
		return;
	}

	if (header[0] != 'B' || header[1] != 'M') {
		std::cout << "[ERROR] : Not a BMP file" << std::endl;
		return;
	}

	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	if (imageSize == 0) { imageSize = width*height * 3; }
	if (dataPos == 0) { dataPos = 54; }

	data = new unsigned char[imageSize];
	fread(data, 1, imageSize, tex);

	fclose(tex);

	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	delete[] data;

	glBindTexture(GL_TEXTURE_2D, 0);
}*/

void Texture::bind() {
	GLenum val = GL_TEXTURE0 + currTex - 1;
	glActiveTexture(val);
	glBindTexture(GL_TEXTURE_2D, texId);
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}