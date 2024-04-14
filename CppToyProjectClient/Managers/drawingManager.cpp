#include "drawingManager.h"

DrawingManager::DrawingManager() : m_backBufferBitmap(NULL)
{
}

void DrawingManager::setBackBufferBitmap(HWND hwnd)
{
	if (m_backBufferBitmap)
	{
		DeleteObject(m_backBufferBitmap);
	}
	HDC hdc = GetDC(hwnd);
	RECT clientRect;
	GetClientRect(hwnd, &clientRect);

	m_backBufferBitmap = CreateCompatibleBitmap(hdc, clientRect.right, clientRect.bottom);
}

void DrawingManager::loadResources()
{
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

void DrawingManager::initialize()
{
	loadResources();
}

void DrawingManager::drawBackground(HWND hwnd, HDC hdc)
{ 
	HDC memoryDc = CreateCompatibleDC(hdc);
	HBITMAP oldBackBufferBitmap = (HBITMAP)SelectObject(memoryDc, m_backBufferBitmap);





	SelectObject(memoryDc, oldBackBufferBitmap);
	DeleteDC(memoryDc);
	ReleaseDC(hwnd, hdc);
	InvalidateRect(hwnd, NULL, FALSE);
} 