#include"Texture.h"

Texture::Texture()
	: width(0), height(0), data(nullptr) {}

void Texture::loadTexture(const char* imagePath) {
	data = stbi_load(imagePath, &width, &height, &nrChannels, 0);

	if (!data) {
		std::cout << "[ERROR] : Not able to load the file" << std::endl;
		return;
	}

	glGenTextures(1, &texId);
	glBindTexture(GL_TEXTURE_2D, texId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	stbi_image_free(data);
	glBindTexture(GL_TEXTURE_2D, 0);
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
	glBindTexture(GL_TEXTURE_2D, texId);
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}