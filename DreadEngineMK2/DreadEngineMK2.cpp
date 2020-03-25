#include <iostream>
#include "gl_core_4_5.h"
#include <crtdbg.h>
#include "glfw3.h"
#include "glm.hpp"
#include "Application3D.h"

void processInput(GLFWwindow* window);

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Application3D* app3D = new Application3D(1280, 720, "DreadEngineMK2");

    //Vertex Shader----------------------------------------------------------------------------
    unsigned int m_vertexShader;
    m_vertexShader = glCreateShader(GL_VERTEX_SHADER); 
    glShaderSource(m_vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(m_vertexShader); 

    //Error checking for the vertex shader 
    int m_sucess;
    char m_infolog[512];
    glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &m_sucess); 
    if (!m_sucess)
    {
        glGetShaderInfoLog(m_vertexShader, 512, NULL, m_infolog);
        std::cout << "ERROR:SAHDER:VERTEX:COMPILATION_FAILED\N" << m_infolog << std::endl;
    }
    //----------------------------------------------------------------------------------------
    //Frag Shader-----------------------------------------------------------------------------
    unsigned int m_fragshader;
    m_fragshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragshader, 1, &fragmentShaderSource, NULL);
    glCompileShader(m_fragshader); 
    //Error checking for frag shader 
    glGetShaderiv(m_fragshader, GL_COMPILE_STATUS, &m_sucess);
    if (!m_sucess)
    {
        glGetShaderInfoLog(m_fragshader, 512, NULL, m_infolog);
        std::cout << "ERROR::SHADER::FRAGMENT:COMPILATION_FAILED\n" << m_infolog << std::endl;
    }
    //----------------------------------------------------------------------------------------

    //Shader program--------------------------------------------------------------------------
    unsigned int m_shaderProgram;
    m_shaderProgram = glCreateProgram(); 

    glAttachShader(m_shaderProgram, m_vertexShader);
    glAttachShader(m_shaderProgram, m_fragshader); 
    glLinkProgram(m_shaderProgram); 

    //Error checking for shader program
    glGetShaderiv(m_shaderProgram, GL_LINK_STATUS, &m_sucess);
    if (!m_sucess)
    {
        glGetProgramInfoLog(m_shaderProgram, 512, NULL, m_infolog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << m_infolog << std::endl;
    }
    //--------------------------------------------------------------------------------------
    //Deleting the shaders 
    glDeleteShader(m_vertexShader);
    glDeleteShader(m_fragshader);

    //Triangle 
    float m_verticies[] =
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //Bind the vertex array object first, then bind and set vertex buffers(s)
        //and the configure vertex arrtibue(s)
    glBindVertexArray(VAO); 
    //Copies our verticies array in a buffer for OpenGl to use 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(m_verticies), m_verticies, GL_STATIC_DRAW);
    //Then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    //Note that this is allowed, the call to glVertexAttribPointer registered VBO
        //as the vertex attribute's bound vertex buffer object so afterwards
        //we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0); 



    //Clearing the screen to a specific colour before starting the game loop 
    glClearColor(0.25f, 0.25f, 0.25f, 1);
    //Enable the depth buffer 
    //glEnable(GL_DEPTH_TEST);

    //Render loop------------------------------------------------------------------
        //Checks if the window has been told to close at the start of each loop 
    while (!glfwWindowShouldClose(app3D->currentContext()))
    {
        //Input check 
        processInput(app3D->currentContext()); 

        //Rendering------------------------

        //Clearing the screen at the start of every loop 
            //COLOR_BUFFER informs OpenGL to wipe the back-buffer colours clean 
            //DEPTH-BUFFER informs it to clear the distance to the closest pixel. To make sure it displays the new image 
        glClear(GL_COLOR_BUFFER_BIT);

        //Draw out first tranle 
        glUseProgram(m_shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3); 

        //Swap buffers so that there isn't any dragging 
        glfwSwapBuffers(app3D->currentContext());
        //Checking if there has been any input events 
        glfwPollEvents(); 
    }
    //-----------------------------------------------------------------------------

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    ////This cleans up all the memory 
    //    //Including the GLFWwindow pointer that I created 
    //glfwTerminate();
    delete app3D;
    app3D = nullptr;
    return 0; 
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
        std::cout << "Exited with key" << std::endl;
    }

}


