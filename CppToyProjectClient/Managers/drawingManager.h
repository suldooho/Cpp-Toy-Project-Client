#pragma once
#include "../Main/framework.h"

class DrawingManager
{
public:
	DrawingManager();
	DrawingManager(const DrawingManager&) = delete;
	DrawingManager(DrawingManager&&) = delete;

private:
	unsigned int m_windowWidth;
	unsigned int m_windowHeight;

private:
	std::vector<HBITMAP> m_bitmaps;

private:
	void setWindowSize(HWND hwnd);
	void loadResources();

private:
	void drawBitmap(HDC hdc, HBITMAP bitmap, int x, int y, float widthMultiply, float heightMultiply);
	void drawMyBackground(HDC hdc);
	void drawOtherBackground(HDC hdc);

public: 
	void initialize();
	void drawBackground(HDC hdc); 
};

