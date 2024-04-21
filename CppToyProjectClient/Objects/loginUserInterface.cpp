#include "../Main/framework.h"

LoginUserInterface::LoginUserInterface(HWND hwnd, HINSTANCE hinstance) : UserInterface()
{
	createControls(hwnd, hinstance);
}

LoginUserInterface::~LoginUserInterface()
{
}

void LoginUserInterface::createControls(HWND hwnd, HINSTANCE hinstance)
{
	RECT windowSize;
	GetClientRect(hwnd, &windowSize);
	
	HWND edit = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, windowSize.right / 2 - 100, windowSize.bottom / 2, 200, 25, hwnd, (HMENU)Control::Edit, hinstance, NULL);
	m_controls.emplace(Control::Edit, edit);
	SendMessage(edit, EM_LIMITTEXT, (WPARAM)m_nickNameMaxLength, 0);

	HWND button = CreateWindow(TEXT("button"), TEXT("Click Me"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, windowSize.right / 2 - 100, windowSize.bottom / 2 + 50, 200, 100, hwnd, (HMENU)Control::ChangeStageButton, hinstance, NULL);
	m_controls.emplace(Control::ChangeStageButton, button);

}

unsigned int LoginUserInterface::getLettersMaxLength() const
{
	return m_nickNameMaxLength;
}

void LoginUserInterface::moveControlsPosition(HWND hwnd)
{
	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	MoveWindow(m_controls[Control::Edit], windowSize.right / 2 - 100, windowSize.bottom / 2, 200, 25, false);
	MoveWindow(m_controls[Control::ChangeStageButton], windowSize.right / 2 - 100, windowSize.bottom / 2 + 50, 200, 100, false);
}
