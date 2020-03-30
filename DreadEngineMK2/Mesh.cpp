#include "Mesh.h"


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteBuffers(1, &m_EBO);
}

void Mesh::setVertexArrays(unsigned int VAO, unsigned int VBO, unsigned int EBO)
{
	m_VAO = VAO;
	m_VBO = VBO;
	m_EBO = EBO; 
}

void Mesh::bind()
{
	glBindVertexArray(m_VAO); 
}