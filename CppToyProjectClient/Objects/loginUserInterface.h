class LoginUserInterface : public UserInterface
{
	const unsigned int m_nickNameMaxLength = 10;
public:
	LoginUserInterface(HWND hwnd, HINSTANCE hinstance);
	virtual ~LoginUserInterface();

	LoginUserInterface() = delete;
	LoginUserInterface(const LoginUserInterface&) = delete;
	LoginUserInterface(LoginUserInterface&&) = delete;

protected:
	virtual void createControls(HWND hwnd, HINSTANCE hinstance) override;
	virtual unsigned int getLettersMaxLength() const;

public:
	virtual void moveControlsPosition(HWND hwnd) override;
};

