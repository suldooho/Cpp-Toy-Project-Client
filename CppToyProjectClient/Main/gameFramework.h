class UserInterface; 
class Player;

enum class PlayerLocation
{
	Connect,
	Login,
	Lobby,
	InGame
};

class GameFramework
{
public:
	static GameFramework& getInstance();

private:
	GameFramework();
	GameFramework(const GameFramework&) = delete;
	GameFramework(GameFramework&&) = delete;

private:  
	PlayerLocation m_playerLocation;
	 
	std::unique_ptr<UserInterface> m_userInterface;
	std::unique_ptr<Player> m_player;

private:
	void deleteCurrentLocation();
	void createLogin(const HWND hwnd, const HINSTANCE hinstance);
	void createLobby(const HWND hwnd, const HINSTANCE hinstance);
	void createInGame(const HWND hwnd, const HINSTANCE hinstance);

public:
	void changeWindowSize(const HWND hwnd);
	void changePlayerLocation(const HWND hwnd, const HINSTANCE hinstance);
	void handleKeyboardLogic(const HWND hwnd, const WPARAM wparam);
	void draw(const HWND hwnd, const HDC dc);
	bool Test = false;
};

