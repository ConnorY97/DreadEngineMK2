#include <iostream>
#include "gl_core_4_5.h"
#include <crtdbg.h>
#include "glfw3.h"
#include "glm.hpp"
#include "Window.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Window* m_Window = new Window();
    

    //Game loop 
        //Checking if the window should close if the escape key is pressed 
    while (glfwWindowShouldClose(m_Window->getWindow()) == false);//&& glfwGetKey(m_Window->getWindow(), GLFW_KEY_ESCAPE != GLFW_PRESS))
    {
        //Clearing the screen at the start of every loop 
            //COLOR_BUFFER informs OpenGL to wipe the back-buffer colours clean 
            //DEPTH-BUFFER informs it to clear the distance to the closest pixel. To make sure it displays the new image 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwPollEvents();
    }
    
    m_Window->~Window();
    delete m_Window;
    m_Window = nullptr;
    return 0; 
}