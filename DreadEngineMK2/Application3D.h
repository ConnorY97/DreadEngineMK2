#pragma once
#include <iostream>
#include "gl_core_4_5.h"
#include "glfw3.h"
#include "glm.hpp"

class Application3D
{
public:

	Application3D(int width, int height, const char* name);
	~Application3D(); 

	int startUp(int width, int height, const char* name); 

	GLFWwindow* currentContext() { return m_window; }


protected:

	int m_appWindowWidth = 1280;
	int m_appWindowHeight = 720;
	const char* m_name; 

	GLFWwindow* m_window; 
};

