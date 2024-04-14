#include "drawingManager.h"

DrawingManager::DrawingManager() : m_windowWidth(0), m_windowHeight(0)
{
} 

void DrawingManager::setWindowSize(HWND hwnd)
{
	RECT rect;
	GetClientRect(hwnd, &rect);
	m_windowWidth = rect.right - rect.left;
	m_windowHeight = rect.bottom - rect.top;
}

void DrawingManager::loadResources()
{
	HBITMAP bitmap; 
	bitmap = (HBITMAP)LoadImage(NULL, TEXT("Resources/testMyBackground.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_bitmaps.emplace_back(bitmap);
}

void DrawingManager::drawBitmap(HDC hdc, HBITMAP bitmap, int x, int y, float widthMultiply, float heightMultiply)
{ 
	HDC memoryHdc = CreateCompatibleDC(hdc);
	HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryHdc, bitmap);

	BITMAP bitmapData;
	GetObject(bitmap, sizeof(BITMAP), &bitmapData); 
	int bitmapWidth = bitmapData.bmWidth;
	int bitmapHeight = bitmapData.bmHeight;

	StretchBlt(hdc, x, y, static_cast<int>(bitmapWidth * widthMultiply), static_cast<int>(bitmapHeight * heightMultiply), memoryHdc, 0, 0, bitmapWidth, bitmapHeight, SRCCOPY);

	SelectObject(memoryHdc, oldBitmap);
	DeleteDC(memoryHdc);
}

void DrawingManager::drawMyBackground(HDC hdc)
{
	for (HBITMAP& bitmap : m_bitmaps)
	{
		drawBitmap(hdc, bitmap, 0, 0, 1.5f, 1.5f);
	}
}

void DrawingManager::drawOtherBackground(HDC hdc)
{
}
 

void DrawingManager::initialize()
{
	loadResources();
}

void DrawingManager::drawBackground(HDC hdc)
{ 
	drawMyBackground(hdc);
	drawOtherBackground(hdc);
} 