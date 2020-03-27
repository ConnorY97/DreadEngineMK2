#pragma once
#include "ext.hpp"
#include "gl_core_4_5.h"
#include "glm.hpp"
#include "glfw3.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
class Shader
{	
public:
	unsigned int shaderID = 0;

	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	~Shader();

	unsigned int CompileShader(unsigned int type, const std::string& source);
	void CheckCompileErrors(GLuint shader, std::string type);
	unsigned int GetID();
	void Use() { glUseProgram(shaderID); }

#pragma region Uniform functions
	// ------------------------------------------------------------------------
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(shaderID, name.c_str()), (int)value);
	}

	// ------------------------------------------------------------------------
	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(shaderID, name.c_str()), value);
	}

	// ------------------------------------------------------------------------
	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(shaderID, name.c_str()), value);
	}

	// ------------------------------------------------------------------------
	void setVec2(const std::string& name, const glm::vec2& value) const
	{
		glUniform2fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]);
	}
	void setVec2(const std::string& name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(shaderID, name.c_str()), x, y);
	}

	// ------------------------------------------------------------------------
	void setVec3(const std::string& name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]);
	}
	void setVec3(const std::string& name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(shaderID, name.c_str()), x, y, z);
	}

	// ------------------------------------------------------------------------
	void setVec4(const std::string& name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(shaderID, name.c_str()), 1, &value[0]);
	}
	void setVec4(const std::string& name, float x, float y, float z, float w)
	{
		glUniform4f(glGetUniformLocation(shaderID, name.c_str()), x, y, z, w);
	}

	// ------------------------------------------------------------------------
	void setMat2(const std::string& name, const glm::mat2& mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	// ------------------------------------------------------------------------
	void setMat3(const std::string& name, const glm::mat3& mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}

	// ------------------------------------------------------------------------
	void setMat4(const std::string& name, const glm::mat4& mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
#pragma endregion
};

