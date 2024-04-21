#include "../Main/framework.h" 

GameFramework& GameFramework::getInstance()
{
	static GameFramework gameFramework;
	return gameFramework;
}

GameFramework::GameFramework() :m_stage(nullptr), m_userInterface(nullptr)
{
}

void GameFramework::initialize(HWND hwnd, HINSTANCE hinstance)
{
	m_stage = std::make_unique<LoginStage>();
	m_userInterface = std::make_unique<LoginUserInterface>(hwnd, hinstance);
}

void GameFramework::changeWindowSize(HWND hwnd)
{ 
	m_userInterface->moveControlsPosition(hwnd);
}

void GameFramework::changeEidt(HWND hwnd)
{
	m_userInterface->changeEidt(hwnd);
}

void GameFramework::draw(HWND hwnd, HDC dc)
{ 
	m_stage->draw(hwnd, dc);
}