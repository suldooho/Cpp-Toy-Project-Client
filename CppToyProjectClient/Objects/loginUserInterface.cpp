#include "../Main/framework.h"

LoginUserInterface::LoginUserInterface(const HWND hwnd, const  HINSTANCE hinstance) : UserInterface()
{
	loadBitmaps();
	createControls(hwnd, hinstance);
}

LoginUserInterface::~LoginUserInterface()
{
}

void LoginUserInterface::loadBitmaps()
{
	HBITMAP bitmap;
	bitmap = (HBITMAP)LoadImage(NULL, TEXT("Resources/Login/testMyBackground.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_bitmaps.emplace_back(bitmap);
}

void LoginUserInterface::createControls(const HWND hwnd, const HINSTANCE hinstance)
{
	HBITMAP bitmap;
	bitmap = (HBITMAP)LoadImage(NULL, TEXT("Resources/Login/testMyBackground.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_bitmaps.emplace_back(bitmap);
	setControlsSize(hwnd);

	RECT windowSize;
	GetClientRect(hwnd, &windowSize);
	
	HWND edit = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, windowSize.right / 2 - m_editWidth / 2, windowSize.bottom / 2, m_editWidth, m_editHeight, hwnd, (HMENU)Control::Edit, hinstance, NULL);
	m_controls.emplace(Control::Edit, edit);
	SendMessage(edit, EM_LIMITTEXT, (WPARAM)m_nickNameMaxLength, 0);

	HWND button = CreateWindow(TEXT("button"), TEXT("Click Me"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, windowSize.right / 2 - m_editWidth / 2, windowSize.bottom / 2 + m_buttonHeight, m_editWidth, m_buttonHeight, hwnd, (HMENU)Control::ChangeStageButton, hinstance, NULL);
	m_controls.emplace(Control::ChangeStageButton, button);

}

void LoginUserInterface::setControlsSize(const HWND hwnd)
{
	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	m_editWidth = windowSize.right / 8;
	m_editHeight = 25;
	m_buttonHeight = windowSize.bottom / 10;
}

void LoginUserInterface::moveControlsPosition(const HWND hwnd)
{
	setControlsSize(hwnd);

	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	MoveWindow(m_controls[Control::Edit], windowSize.right / 2 - m_editWidth / 2, windowSize.bottom / 2, m_editWidth, m_editHeight, false);
	MoveWindow(m_controls[Control::ChangeStageButton], windowSize.right / 2 - m_editWidth / 2, windowSize.bottom / 2 + m_buttonHeight, m_editWidth, m_buttonHeight, false);
}

void LoginUserInterface::draw(const HWND hwnd, const HDC dc)
{
}
