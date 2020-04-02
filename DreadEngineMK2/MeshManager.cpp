#include "MeshManager.h"
#include <vector>

MeshManager::~MeshManager()
{
	for (int i = 0; i < m_meshs.size(); i++)
	{
		delete m_meshs[i];
		m_meshs[i] = nullptr; 
	}
}

void MeshManager::makeUntexCube(glm::vec3 size, glm::vec3 pos, glm::vec3 colour)
{
	Mesh* tempM = new Mesh();
	m_meshs.push_back(tempM); 
	
	std::vector<float> verticies =
	{	
		//Back plane 
		/*0*/-0.5f, -0.5f, -0.5f, colour.x, colour.y, colour.z,		//Back bottom left
		/*1*/0.5f, -0.5f, -0.5f, colour.x, colour.y, colour.z,		//Back bottom right 
		/*2*/-0.5f, 0.5f, -0.5f, colour.x, colour.y, colour.z,		//Back top left 
		/*3*/0.5f, 0.5f, -0.5f, colour.x, colour.y, colour.z,		//Back top right 

		//Front plane 
		/*4*/-0.5f, -0.5f, 0.5f, colour.x, colour.y, colour.z,		//Front bottom left 
		/*5*/0.5f, -0.5f, 0.5f, colour.x, colour.y, colour.z,		//Front bottom right 
		/*6*/-0.5f, 0.5f, 0.5f, colour.x, colour.y, colour.z,		//Front top left 
		/*7*/0.5f, 0.5f, 0.5f, colour.x, colour.y, colour.z,		//Front top right 
	};
	std::vector<unsigned int> indices =
	{
		//Back
		0, 1, 2,
		0, 3, 2,
		//Right 
		0, 4, 7,
		0, 3, 7,
		//Bottom
		0, 1, 4,
		1, 5, 4,
		//Left
		1, 2, 6,
		1, 5, 6,
		//Top
		3, 2, 7,
		2, 6, 7,
		//Front 
		4, 5, 6,
		4, 7, 6
	};
	
	//Creating the mesh 
	unsigned int VAO, VBO, EBO; 

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(float), verticies.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	//Position attribute 
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	m_meshs[m_meshs.size() - 1]->setVertexArrays(VAO, VBO, EBO); 
	m_meshs[m_meshs.size() - 1]->setPos(pos);
	m_meshs[m_meshs.size() - 1]->setScale(size); 
	m_meshs[m_meshs.size() - 1]->setIncicesAmount(indices.size());
	
	//Unbinding the VBO 
	glBindBuffer(GL_ARRAY_BUFFER, 0); 
	//Unbinding the EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//Unbinding the VAO
	glBindVertexArray(0);
	
}

void MeshManager::draw(Shader* shader)
{
	for (int i = 0; i < m_meshs.size(); i++)
	{
		glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		shader->setMat4("view", view); 

		m_meshs[i]->bind(); 
		glm::mat4 model = glm::mat4(1.0f); 
		model = glm::translate(model, m_meshs[i]->getPos());
		shader->setMat4("model", model); 

		glDrawElements(GL_TRIANGLES, m_meshs[i]->getIndicesAmount(), GL_UNSIGNED_INT, 0);		
		//glDrawArrays(GL_TRIANGLES, 0, 7);
	}
}
