class LobbyUserInterface : public UserInterface
{
public:
	LobbyUserInterface(const HWND hwnd, const HINSTANCE hinstance);
	virtual ~LobbyUserInterface();

	LobbyUserInterface() = delete;
	LobbyUserInterface(const LobbyUserInterface&) = delete;
	LobbyUserInterface(LobbyUserInterface&&) = delete;

private:
	static const unsigned int m_roomNamingMaxLength = 10;
	unsigned int m_buttonWidth;
	unsigned int m_buttonHeight;

protected:
	virtual void createControls(const HWND hwnd, const HINSTANCE hinstance) override;
	virtual void setControlsSize(const HWND hwnd) override;

public:
	virtual void moveControlsPosition(const HWND hwnd) override;
};

