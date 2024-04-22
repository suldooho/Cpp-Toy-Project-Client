class LoginUserInterface : public UserInterface
{
public:
	LoginUserInterface(const HWND hwnd, const HINSTANCE hinstance);
	virtual ~LoginUserInterface();

	LoginUserInterface() = delete;
	LoginUserInterface(const LoginUserInterface&) = delete;
	LoginUserInterface(LoginUserInterface&&) = delete;

private:
	static const unsigned int m_nickNameMaxLength = 10;
	unsigned int m_editWidth;
	unsigned int m_editHeight;
	unsigned int m_buttonHeight;

protected:
	virtual void createControls(const HWND hwnd, const HINSTANCE hinstance) override;
	virtual void setControlsSize(const HWND hwnd) override;

public:
	virtual void moveControlsPosition(const HWND hwnd) override;
};

