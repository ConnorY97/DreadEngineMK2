#pragma once
#include "Texture.h"
#include <vector>

class TextureManger
{
public:
	~TextureManger(); 

	void loadTexture(const char* filePath); 

	unsigned int getPos(int index) { return m_textures[index]->getPos(); }

protected:
	std::vector<Texture*> m_textures; 
};

