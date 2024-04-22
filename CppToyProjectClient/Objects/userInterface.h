enum class Control
{
	Edit,
	ChangeStageButton,
	CreateRoomMakeButton,
	ChattingContentsScroll,
	Button3,
	Button4
};

class UserInterface
{
protected:
	UserInterface();
	UserInterface(const UserInterface&) = delete;
	UserInterface(UserInterface&&) = delete;

public:
	virtual ~UserInterface();

protected:
	std::vector<HBITMAP> m_bitmaps;
	std::unordered_map<Control, HWND> m_controls;

protected:
	virtual void loadBitmaps() = 0;
	virtual void createControls(const HWND hwnd, const HINSTANCE hinstance) = 0;
	virtual void setControlsSize(const HWND hwnd) = 0;

public:
	virtual void moveControlsPosition(const HWND hwnd) = 0;
	virtual void draw(const HWND hwnd, const HDC dc) = 0;
};

