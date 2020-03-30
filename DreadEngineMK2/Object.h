#pragma once
#include "glm.hpp"

class Mesh;
class Texture; 

class Object
{
protected:
	glm::vec3	m_position;
	glm::vec3	m_scale; 

	Mesh*		m_mesh;
	
	Texture*	m_texture; 
	
};

