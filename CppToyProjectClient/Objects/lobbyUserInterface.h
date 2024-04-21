class LobbyUserInterface : public UserInterface
{
private:
	const unsigned int m_chattingMaxLength = 10;
	const unsigned int m_roomNamingMaxLength = 10;

public:
	LobbyUserInterface(HWND hwnd, HINSTANCE hinstance);
	virtual ~LobbyUserInterface();

	LobbyUserInterface() = delete;
	LobbyUserInterface(const LobbyUserInterface&) = delete;
	LobbyUserInterface(LobbyUserInterface&&) = delete;

protected:
	virtual void createControls(HWND hwnd, HINSTANCE hinstance) override;
	virtual unsigned int getLettersMaxLength() const;

public:
	virtual void moveControlsPosition(HWND hwnd) override;
};

