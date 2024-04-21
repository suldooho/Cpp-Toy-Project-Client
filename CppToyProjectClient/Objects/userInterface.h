enum class Control
{
	Edit = 0,
	ChangeStageButton = 1,
	Button2 = 2,
	Button3 = 3,
	Button4 = 4
};

class UserInterface
{
protected:
	static const unsigned int m_lettersLength = 100;

	wchar_t m_editLetters[m_lettersLength];
	std::unordered_map<Control, HWND> m_controls;

protected:
	UserInterface();
	UserInterface(const UserInterface&) = delete;
	UserInterface(UserInterface&&) = delete;

public:
	virtual ~UserInterface();

protected:
	virtual void createControls(HWND hwnd, HINSTANCE hinstance) = 0; 
	virtual unsigned int getLettersMaxLength() const = 0;

public:
	virtual void moveControlsPosition(HWND hwnd) = 0;
	void changeEidt(const HWND hwnd);
};

