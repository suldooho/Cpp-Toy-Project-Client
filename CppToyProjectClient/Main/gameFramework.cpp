#include "../Main/framework.h" 

GameFramework& GameFramework::getInstance()
{
	static GameFramework gameFramework;
	return gameFramework;
}

GameFramework::GameFramework() : m_playerLocation(PlayerLocation::Login)
{
	m_drawingManager = std::make_unique<DrawingManager>();
}

void GameFramework::initialize()
{
	m_drawingManager->initialize();
}

void GameFramework::changeWindowSize(HWND hwnd)
{
	m_drawingManager->setBackBufferBitmap(hwnd);
}
