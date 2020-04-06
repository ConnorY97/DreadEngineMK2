#pragma once
#include <vector>
#include "glm.hpp"
#include "gl_core_4_5.h"
#include <string>

class Shader;
//
//struct Vertex
//{
//	glm::vec3 pos;
//	glm::vec3 norm;
//	glm::vec2 texCoords;
//};
//
//struct Texture
//{
//	unsigned int ID;
//	std::string type; 
//};

class Mesh
{
public:
    /*  Mesh Data  */
    //std::vector<Vertex> m_vertices;
    //std::vector<unsigned int> m_indices;
    //std::vector<Texture> m_textures;
    /*  Functions  */
    //Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
    //void Draw(Shader shader);

    void setVertexArrays(unsigned int VAO, unsigned int VBO, unsigned int EBO)
    {
        m_VAO = VAO;
        m_VBO = VBO;
        m_EBO = EBO;
    }

    void setPos(glm::vec3 pos) { m_pos = pos; }
    void setScale(glm::vec3 scale) { m_scale = scale; }
    void setIncicesAmount(int indicies) { indicesAmount = indicies; }

    void bind()
    {
        glBindVertexArray(m_VAO); 
    }

    glm::vec3 getPos() { return m_pos; }

    int getIndicesAmount() { return indicesAmount; }

    
private:
    /*  Render data  */
    unsigned int m_VAO, m_VBO, m_EBO;
    /*  Functions    */
    //void setupMesh();

    glm::vec3 m_pos;
    glm::vec3 m_scale; 
    int indicesAmount; 

};

