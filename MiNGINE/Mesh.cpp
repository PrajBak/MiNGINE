#pragma once
#include"Mesh.h"

Mesh::Mesh(std::vector<float>& _vertexCords, std::vector<float>& _colorCords, std::vector<float> _texCords, std::vector<unsigned int>& _indices)
	:vertexCords(_vertexCords), colorCords(_colorCords), texCords(_texCords), indices(_indices)
{	
}

void Mesh::addMesh() {
	unsigned int* ind = &indices[0];
	float* vertex = &vertexCords[0];
	float* color = &colorCords[0];
	float* tex = &texCords[0];
	vao = new VertexArrayBuffer();
	ibo = new IndexBuffer(ind, indices.size());
	vao->addVertexBuffer(new VertexBuffer(vertex, vertexCords.size(), 3), 0);
	vao->addVertexBuffer(new VertexBuffer(color, colorCords.size(), 3), 1);
	vao->addVertexBuffer(new VertexBuffer(tex, texCords.size(), 2), 2);
}

void Mesh::drawMesh() {
	vao->bind();
	ibo->bind();
	glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Mesh::endMesh() {
	vao->unbind();
	ibo->unbind();
	delete vao;
	delete ibo;
}