class LoginStage : public Stage
{
public:
	LoginStage();
	virtual ~LoginStage();

	LoginStage(const LoginStage&) = delete;
	LoginStage(LoginStage&&) = delete;

protected:
	virtual void loadBitmaps() override;

public:
	virtual void draw(const HWND hwnd, const HDC dc) const override;
};

