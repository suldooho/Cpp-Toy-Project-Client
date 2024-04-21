class Stage;
class UserInterface;

class GameFramework
{
public:
	static GameFramework& getInstance();

private:
	GameFramework();
	GameFramework(const GameFramework&) = delete;
	GameFramework(GameFramework&&) = delete;

private:  
	std::unique_ptr<Stage> m_stage;
	std::unique_ptr<UserInterface> m_userInterface;

public:
	void initialize(HWND hwnd, HINSTANCE hinstance);
	void changeWindowSize(HWND hwnd);
	void changeEidt(HWND hwnd);
	void draw(HWND hwnd, HDC dc);
};

