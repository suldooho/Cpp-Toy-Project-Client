class Stage;
class UserInterface;

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

	std::unique_ptr<Stage> m_stage;
	std::unique_ptr<UserInterface> m_userInterface;

private:
	void createLogin(HWND hwnd, HINSTANCE hinstance);
	void createLobby(HWND hwnd, HINSTANCE hinstance);
	void createInGame(HWND hwnd, HINSTANCE hinstance);
	void deleteCurrentStage();

public:
	void changeWindowSize(HWND hwnd);
	void changeEidt(HWND hwnd);
	void changePlayerLocation(HWND hwnd, HINSTANCE hinstance);
	void draw(HWND hwnd, HDC dc);

};

