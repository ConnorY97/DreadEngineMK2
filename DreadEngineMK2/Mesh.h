#pragma once
#include <vector>
#include "glm.hpp"
#include "gl_core_4_5.h"

struct Vertex
{
	Vertex(glm::vec3 aVertex, glm::vec2 aColour)
	{
		vertex = aVertex;
		colour = aColour; 
		texCoord = glm::vec2(0.0f);
	}
	Vertex(glm::vec3 aVertex, glm::vec2 aColour, glm::vec3 aTexCoord)
	{
		vertex = aVertex;
		colour = aColour;
		texCoord = aTexCoord;
	}
	glm::vec3 vertex;
	glm::vec2 colour;
	glm::vec2 texCoord;
};

class Mesh
{
public:
	~Mesh(); 

	void setVertexArrays(unsigned int VAO, unsigned int VBO, unsigned int EBO);
	
	void setPos(glm::vec3 pos) { m_pos = pos; }
	glm::vec3 getPos() { return m_pos; }

	void setScale(glm::vec3 scale) { m_scale = scale; }
	glm::vec3 getScale() { return m_scale; }

	void setIncicesAmount(unsigned int indicesamount) { m_indicesAmount = indicesamount; }
	unsigned int getIndicesAmount() { return m_indicesAmount; }

	unsigned int getVAO() { return m_VAO; }
	unsigned int getEBO() { return m_EBO; }

	void bind(); 

protected:
	unsigned int m_VAO, m_VBO, m_EBO;
	glm::vec3 m_pos; 
	glm::vec3 m_scale; 
	unsigned int m_indicesAmount; 
};

