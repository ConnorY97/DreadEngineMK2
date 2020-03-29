#pragma once
#include "Texture.h"
#include <vector>

class TextureManger
{
public:
	~TextureManger(); 

	void loadTexture(const char* filePath); 

	int arraySize() { return m_textures.size() - 1; }

	unsigned int getPos(int index) { return m_textures[index]->getPos(); }

protected:
	std::vector<Texture*> m_textures; 
};

