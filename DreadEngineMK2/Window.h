#pragma once
#include "gl_core_4_5.h"
#include <crtdbg.h>
#include "glfw3.h"
#include "glm.hpp"
#include <string>
class Window
{
public:
	Window();

	~Window(); 

	GLFWwindow* getWindow(); 

private:
	GLFWwindow* m_window = nullptr; 
};

