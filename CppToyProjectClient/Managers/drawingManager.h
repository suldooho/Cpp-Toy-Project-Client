#pragma once
#include "../framework.h"

class DrawingManager
{
private:
	static DrawingManager* m_instance;

	DrawingManager* getInstance()
	{
		if (!m_instance)
		{
			m_instance = this;
		}

		return m_instance;
	}

private:
	std::vector<HBITMAP> bitmaps;

public:
	DrawingManager() = delete;
	DrawingManager(unsigned int windowWidth, unsigned int windowHeight);
	
private:
	unsigned int m_windowWidth;
	unsigned int m_windowHeight;

private:
	void drawMyBackground(HDC hdc);
	void drawOtherBackground(HDC hdc);

public:
	void loadResources(HINSTANCE instance);
	void drawBackground(HDC hdc);
};

