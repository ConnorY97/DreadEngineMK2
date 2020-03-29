#include "TextureManger.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "gl_core_4_5.h"
#include <iostream>

TextureManger::~TextureManger()
{
	//When removing elements from the list you want to go down 
		//So set i to the variable and set i greather than 0
	for (int i = 0; i < m_textures.size(); i++)
	{
		delete m_textures[i];
		m_textures[i] = nullptr;
	}
}

void TextureManger::loadTexture(const char* filePath)
{
	Texture* temp = new Texture(); 
	m_textures.push_back(temp); 
	//The next index in the array to set the new texture to 
	unsigned int texture;

	stbi_set_flip_vertically_on_load(true);

	//Load and create texture 
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Load image from file 
	int w, h, rgb; 
	//stbi_set_flip_vertically_on_load(true); 
	unsigned char* data = stbi_load(filePath, &w, &h, &rgb, 0);
	if (data)
	{
		if (rgb == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		if (rgb == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	//Memory clearing 
	stbi_image_free(data);

	m_textures[m_textures.size() - 1]->setPos(texture);
	m_textures[m_textures.size() - 1]->setPath(filePath);
}
