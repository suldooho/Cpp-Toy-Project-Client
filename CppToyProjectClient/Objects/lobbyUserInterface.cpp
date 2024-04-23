#include "../Main/framework.h"

LobbyUserInterface::LobbyUserInterface(const HWND hwnd, const HINSTANCE hinstance)
{
	loadBitmaps();
	createControls(hwnd, hinstance);
}

LobbyUserInterface::~LobbyUserInterface()
{
}

void LobbyUserInterface::loadBitmaps()
{
	HBITMAP bitmap;
	bitmap = (HBITMAP)LoadImage(NULL, TEXT("Resources/Login/testOtherBackground.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_bitmaps.emplace_back(bitmap);
}

void LobbyUserInterface::createControls(const HWND hwnd, const HINSTANCE hinstance)
{
	setControlsSize(hwnd);

	RECT windowSize;
	GetClientRect(hwnd, &windowSize); 

	HWND button = CreateWindow(TEXT("button"), TEXT("Create Room"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0, windowSize.bottom - m_buttonHeight, m_buttonWidth, m_buttonHeight, hwnd, (HMENU)Control::CreateRoomMakeButton, hinstance, NULL);
	m_controls.emplace(Control::CreateRoomMakeButton, button);
}

void LobbyUserInterface::setControlsSize(const HWND hwnd)
{
	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	m_buttonWidth = windowSize.right / 3 * 2 - 25;
	m_buttonHeight = windowSize.bottom / 6;
}

void LobbyUserInterface::moveControlsPosition(const HWND hwnd)
{
	setControlsSize(hwnd);

	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	MoveWindow(m_controls[Control::CreateRoomMakeButton], 0, windowSize.bottom - m_buttonHeight, m_buttonWidth, m_buttonHeight, false);
}

void LobbyUserInterface::draw(const HWND hwnd, const HDC dc)
{
	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	HDC memoryDc = CreateCompatibleDC(dc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryDc, m_bitmaps[0]);
	BITMAP bitmapInformation;
	GetObject(m_bitmaps[0], sizeof(BITMAP), &bitmapInformation);

	StretchBlt(dc, 0, 0, windowSize.right, windowSize.bottom, memoryDc, 0, 0, bitmapInformation.bmWidth, bitmapInformation.bmHeight, SRCCOPY);
	SelectObject(memoryDc, oldBitmap);

	DeleteDC(memoryDc);
}
