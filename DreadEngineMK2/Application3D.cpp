#include "Application3D.h"

int windowWidth, windowHeight;

//OpneGL functions have to s
void framebufferSizeCallBack(GLFWwindow* window, int width, int height);




Application3D::Application3D(int width, int height, const char* name)
{
    startUp(width, height, name); 
}

Application3D::~Application3D()
{
    //This cleans up all the memory 
        //Including the GLFWwindow pointer that I created 
    glfwTerminate();
}

int Application3D::startUp(int width, int height, const char* name)
{
    //Initialising GLFW 
    glfwInit();

    m_window = glfwCreateWindow(width, height, name, NULL, NULL);

    //Setting the version of GLFW we want to use 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    //Checking the window got created if it failed end the program 
    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }


    glfwMakeContextCurrent(m_window);

    //Updates the size of the render window if the user changes it 
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallBack);

    //Remap all OpenGL's functions to the correct versions and feature sets
    if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
    {
        std::cout << "Failed to remap openGL functions" << std::endl;
        glfwDestroyWindow(m_window);
        glfwTerminate();
        return -3;
    }

    //Test which version of OpenGL is running
    auto major = ogl_GetMajorVersion();
    auto minor = ogl_GetMinorVersion();
    printf("GL: %i.%i\n", major, minor);

   
}

void framebufferSizeCallBack(GLFWwindow* window, int width, int height)
{
    glfwGetCurrentContext();
    glfwGetWindowSize(window, &width, &height); 
    windowWidth = width;
    windowHeight = height;
    //Set the size of the rendering window  
    glViewport(0, 0, width, height);
}

