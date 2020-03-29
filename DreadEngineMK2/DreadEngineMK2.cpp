#include <iostream>
#include "gl_core_4_5.h"
#include <crtdbg.h>
#include "glfw3.h"
#include "glm.hpp"
#include "Application3D.h"
#include "Shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Application3D* app3D = new Application3D(1280, 720, "DreadEngineMK2");


    Shader* m_simpleShader = new Shader("../Shaders/vert_shader.shader", "../Shaders/frag_shader.shader"); 


#pragma region Shape
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        // positions          // colors           // texture coords
        -0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
                 
        -0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
                  
        -0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
                    
         0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
                     
        -0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
          
        -0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.1f, 0.1f, 0.1f,   0.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    glm::vec3 cubePositions[] =
    {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    
#pragma endregion

#pragma region Texture
    // load and create a texture 
   // -------------------------
    unsigned int texture, texture2;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    //Flipping textures the right way up 
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("../Images/container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    //Memory cleaning 
    stbi_image_free(data);
    // texture 2
   // ---------
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    data = stbi_load("../Images/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
#pragma endregion



   

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    m_simpleShader->Use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    m_simpleShader->setInt("texture1", 0);
    // or set it via the texture class
    m_simpleShader->setInt("texture2", 1);

    


    //Note that this is allowed, the call to glVertexAttribPointer registered VBO
    //as the vertex attribute's bound vertex buffer object so afterwards
    //we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0); 


    glPolygonMode(GL_FRONT, GL_FILL);


    //Clearing the screen to a specific colour before starting the game loop 
    glClearColor(0.25f, 0.25f, 0.25f, 1);
    //Enable the depth buffer 
    glEnable(GL_DEPTH_TEST);

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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Bind the texture on corrisponding texture units 
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        // create transformations
        glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        // pass transformation matrices to the shader
        m_simpleShader->setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        m_simpleShader->setMat4("view", view);

        glBindVertexArray(VAO);

        for (unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            m_simpleShader->setMat4("model", model);
            //REMEBER
                //If using an EBO you must use gldrawelements so that they are drawn in the correct order 
                //or you will get weird errors like only half of the rectangle being drawn 
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        

        //Swap buffers so that there isn't any dragging 
        glfwSwapBuffers(app3D->currentContext());
        //Checking if there has been any input events 
        glfwPollEvents(); 
    }
    //-----------------------------------------------------------------------------

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    ////This cleans up all the memory 
    //    //Including the GLFWwindow pointer that I created 
    //glfwTerminate();
    delete m_simpleShader;
    m_simpleShader = nullptr;
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