#include "../Main/framework.h" 

GameFramework& GameFramework::getInstance()
{
	static GameFramework gameFramework;
	return gameFramework;
}

GameFramework::GameFramework() : m_playerLocation(PlayerLocation::Connect), m_stage(nullptr), m_userInterface(nullptr)
{ 
} 

void GameFramework::createLogin(HWND hwnd, HINSTANCE hinstance)
{
	m_stage = std::make_unique<LoginStage>();
	m_userInterface = std::make_unique<LoginUserInterface>(hwnd, hinstance);
}

void GameFramework::createLobby(HWND hwnd, HINSTANCE hinstance)
{
	m_stage = std::make_unique<LobbyStage>();
	m_userInterface = std::make_unique<LobbyUserInterface>(hwnd, hinstance);
}

void GameFramework::createInGame(HWND hwnd, HINSTANCE hinstance)
{
}

void GameFramework::deleteCurrentStage()
{
	if (m_stage != nullptr)
	{
		m_stage.reset();
	}

	if (m_userInterface != nullptr)
	{
		m_userInterface.reset();
	}
}


void GameFramework::changeWindowSize(HWND hwnd)
{ 
	m_userInterface->moveControlsPosition(hwnd);
}

void GameFramework::changeEidt(HWND hwnd)
{
	m_userInterface->changeEidt(hwnd);
}

void GameFramework::changePlayerLocation(HWND hwnd, HINSTANCE hinstance)
{
	deleteCurrentStage();
	switch (m_playerLocation)
	{
	case PlayerLocation::Connect:
		createLogin(hwnd, hinstance); 
		m_playerLocation = PlayerLocation::Login;
		break;
	case PlayerLocation::Login:
		createLobby(hwnd, hinstance);
		m_playerLocation = PlayerLocation::Lobby;
		break;
	case PlayerLocation::Lobby:
		createInGame(hwnd, hinstance);
		m_playerLocation = PlayerLocation::InGame;
		break;
	case PlayerLocation::InGame:
		createLobby(hwnd, hinstance);
		m_playerLocation = PlayerLocation::Lobby;
		break;
	}
}

void GameFramework::draw(HWND hwnd, HDC dc)
{ 
	m_stage->draw(hwnd, dc);
}