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
}
