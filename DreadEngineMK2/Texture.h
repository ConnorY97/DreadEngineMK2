#pragma once

class Texture
{
public:
	unsigned int getPos() { return m_pos; }
	void setPos(unsigned int pos) { m_pos = pos; }

	const char* getPath() { return m_filePath; }
	void setPath(const char* filepath) { m_filePath = filepath; }

protected:
	const char* m_filePath; 
	unsigned int m_pos; 
};
