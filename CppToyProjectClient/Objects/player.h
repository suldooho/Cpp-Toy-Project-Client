class ChattingComponent;

class Player
{
public:
	Player(const HWND hwnd, const HINSTANCE hinstance);
	virtual ~Player();

	Player() = delete;
	Player(const Player&) = delete;
	Player(Player&&) = delete;
	 
private:
	std::unique_ptr<ChattingComponent> chattingComponent;

public:
	void moveComponentsPosition(const HWND hwnd);
	void sendMessage(const HWND hwnd);
	void draw(const HWND hwnd, const HDC dc);
};

