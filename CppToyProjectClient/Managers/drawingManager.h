#pragma once
#include "../Main/framework.h"

class DrawingManager
{  
private:
	HINSTANCE m_instance;
	HWND m_hwnd;
	unsigned int m_windowWidth;
	unsigned int m_windowHeight;

private:
	std::vector<HBITMAP> m_bitmaps;

private:
	void setWindowSize();
	void loadResources();

private:
	void drawBitmap(HDC hdc, HBITMAP bitmap, int x, int y, float widthMultiply, float heightMultiply);
	void drawMyBackground(HDC hdc);
	void drawOtherBackground(HDC hdc);

public:
	void initialize(HINSTANCE instance, HWND hwnd);
	void drawBackground(HDC hdc); 
};

