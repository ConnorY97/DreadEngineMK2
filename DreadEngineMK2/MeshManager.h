#pragma once
#include "Mesh.h"
#include <vector>
#include "Shader.h"

class MeshManager
{
public:
	~MeshManager(); 

	void makeUntexCube(glm::vec3 size, glm::vec3 pos, glm::vec3 colour);

	void draw(Shader* shader); 
protected:
	std::vector<Mesh*> m_meshs; 
};

