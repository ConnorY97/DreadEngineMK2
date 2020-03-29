#include "Texture.h"

Texture::~Texture()
{
	glDeleteTextures(1, &m_pos); 
}
