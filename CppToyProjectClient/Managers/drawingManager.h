#pragma once
#include "../Main/framework.h"

class DrawingManager
{
public:
	DrawingManager();
	DrawingManager(const DrawingManager&) = delete;
	DrawingManager(DrawingManager&&) = delete;

private:
	HBITMAP m_backBufferBitmap;

private:
	void loadResources();

private:
	void drawBitmap(HDC hdc, HBITMAP bitmap, int x, int y, float widthMultiply, float heightMultiply);

public: 
	void initialize();
	void setBackBufferBitmap(HWND hwnd);

public:
	void drawBackground(HWND hwnd, HDC hdc);
};

