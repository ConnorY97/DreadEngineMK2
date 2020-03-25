#include <iostream>
#include "gl_core_4_5.h"
#include <crtdbg.h>
#include "glfw3.h"
#include "glm.hpp"
#include "Application3D.h"

//Function forward declarations----------------------------------------------------
void framebufferSizeCallBack(GLFWwindow* window, int width, int height); 
void processInput(GLFWwindow* window); 

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Application3D* app3D = new Application3D(1280, 720, "DreadEngineMK2");

#pragma region Test
    ////Initialising GLFW 
    //glfwInit();

    ////Setting the version of GLFW we want to use 
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    ////Creating the window 
    //GLFWwindow* m_window = glfwCreateWindow(1280, 720, "DreadCoreMK2", NULL, NULL);

    ////Checking the window got created if it failed end the program 
    //if (m_window == NULL)
    //{
    //    std::cout << "Failed to create GLFW window" << std::endl;
    //    glfwTerminate();
    //    return -1;
    //}

    //glfwMakeContextCurrent(m_window);
    ////Updates the size of the render window if the user changes it 
    //glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallBack);

    ////Remap all OpenGL's functions to the correct versions and feature sets
    //if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
    //{
    //    std::cout << "Failed to remap openGL functions" << std::endl;
    //    glfwDestroyWindow(m_window);
    //    glfwTerminate();
    //    return -3;
    //}

    ////Test which version of OpenGL is running
    //auto major = ogl_GetMajorVersion();
    //auto minor = ogl_GetMinorVersion();
    //printf("GL: %i.%i\n", major, minor);
#pragma endregion

    

    //Clearing the screen to a specific colour before starting the game loop 
    glClearColor(0.25f, 0.25f, 0.25f, 1);
    //Enable the depth buffer 
    //glEnable(GL_DEPTH_TEST);

    //Render loop------------------------------------------------------------------
        //Checks if the window has been told to close at the start of each loop 
    while (!glfwWindowShouldClose(app3D->currentContext()))
    {
        //Check if the escape key has been pressed and the window should close 
            //Input
        processInput(app3D->currentContext()); 

        //Rendering------------------------

        //Clearing the screen at the start of every loop 
            //COLOR_BUFFER informs OpenGL to wipe the back-buffer colours clean 
            //DEPTH-BUFFER informs it to clear the distance to the closest pixel. To make sure it displays the new image 
        glClear(GL_COLOR_BUFFER_BIT);

        //Swap buffers so that there isn't any dragging 
        glfwSwapBuffers(app3D->currentContext());
        //Checking if there has been any input events 
        glfwPollEvents(); 
    }
    //-----------------------------------------------------------------------------

    ////This cleans up all the memory 
    //    //Including the GLFWwindow pointer that I created 
    //glfwTerminate();
    delete app3D;
    app3D = nullptr;
    return 0; 
}



