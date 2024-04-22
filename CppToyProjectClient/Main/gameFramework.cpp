#include "../Main/framework.h" 

GameFramework& GameFramework::getInstance()
{
	static GameFramework gameFramework;
	return gameFramework;
}

GameFramework::GameFramework() : m_playerLocation(PlayerLocation::Connect), m_stage(nullptr), m_userInterface(nullptr), m_player(nullptr)
{ 
}

void GameFramework::deleteCurrentLocation()
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

void GameFramework::createLogin(const HWND hwnd, const HINSTANCE hinstance)
{
	m_stage = std::make_unique<LoginStage>();
	m_userInterface = std::make_unique<LoginUserInterface>(hwnd, hinstance);
}

void GameFramework::createLobby(const HWND hwnd, const HINSTANCE hinstance)
{
	m_stage = std::make_unique<LobbyStage>();
	m_userInterface = std::make_unique<LobbyUserInterface>(hwnd, hinstance);
	m_player = std::make_unique<Player>(hwnd, hinstance);
}

void GameFramework::createInGame(const HWND hwnd, const HINSTANCE hinstance)
{
} 

void GameFramework::changeWindowSize(const HWND hwnd)
{ 
	if (m_userInterface)
	{
		m_userInterface->moveControlsPosition(hwnd);
	}

	if (m_player)
	{
		m_player->moveComponentsPosition(hwnd);
	}
}

void GameFramework::changePlayerLocation(const HWND hwnd, const HINSTANCE hinstance)
{
	deleteCurrentLocation();
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

void GameFramework::handleKeyboardLogic(const HWND hwnd, const WPARAM wparam)
{
	switch (wparam)
	{
	case VK_RETURN:
		if (m_player)
		{ 
			m_player->sendMessage(hwnd);
		}
		break;
	}
}

void GameFramework::draw(const HWND hwnd, const HDC dc)
{ 
	if (m_stage)
	{
		//m_stage->draw(hwnd, dc); 
	}

	if (m_player)
	{
		m_player->draw(hwnd, dc);
	}
}