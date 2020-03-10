#include "Window.h"

Window::Window()
{
    //Initiating the GLFW system
        //Checking if it worked
    if (glfwInit() == false)
    {
        printf("ERROR 01: Failed to initialise GLFW system");
    }

    //Creating the window 
    m_window = glfwCreateWindow(1280, 720, "DreadEngine", nullptr, nullptr);

    //Checking if the window was created
    if (m_window == nullptr)
    {
        glfwTerminate();
        printf("ERROR 02: Window failed to be created");
    }

    glfwMakeContextCurrent(m_window);

    //Remap all OPenGL's functions to the correct versions and feature sets 
    if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
        printf("Error 03: Failed to remap OpenGL functions");
    }

    //Test which version of OpenGl the program is running 
    auto major = ogl_GetMajorVersion();
    auto minor = ogl_GetMinorVersion();
    printf("Running GL Version: %i.%i\n", major, minor);
    
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

GLFWwindow* Window::getWindow()
{
    return glfwGetCurrentContext(); 
}