#include "drawingManager.h"

DrawingManager::DrawingManager(unsigned int windowWidth, unsigned int windowHeight) : m_windowWidth(windowWidth), m_windowHeight(windowHeight)
{
}

void DrawingManager::drawMyBackground(HDC hdc)
{
}

void DrawingManager::drawOtherBackground(HDC hdc)
{
}

void DrawingManager::loadResources(HINSTANCE instance)
{
}

void DrawingManager::drawBackground(HDC hdc)
{
	HDC memDC;

	drawMyBackground(hdc);
	drawOtherBackground(hdc);
}
