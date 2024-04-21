#include "../Main/framework.h"

LobbyUserInterface::LobbyUserInterface(HWND hwnd, HINSTANCE hinstance)
{
	createControls(hwnd, hinstance);
}

LobbyUserInterface::~LobbyUserInterface()
{
}

void LobbyUserInterface::createControls(HWND hwnd, HINSTANCE hinstance)
{
	RECT windowSize;
	GetClientRect(hwnd, &windowSize); 

	HWND button = CreateWindow(TEXT("button"), TEXT("Click Me"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, windowSize.right / 2 - 100, windowSize.bottom / 2 + 50, 200, 100, hwnd, (HMENU)Control::ChangeStageButton, hinstance, NULL);
	m_controls.emplace(Control::ChangeStageButton, button);
}

unsigned int LobbyUserInterface::getLettersMaxLength() const
{
	// 현제 포커스되어있는 에디트박스 정보 얻어오기
	return 0;
}

void LobbyUserInterface::moveControlsPosition(HWND hwnd)
{
}
