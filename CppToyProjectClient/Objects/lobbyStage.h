class LobbyStage : public Stage
{
public:
	LobbyStage();
	virtual ~LobbyStage();

	LobbyStage(const LobbyStage&) = delete;
	LobbyStage(LobbyStage&&) = delete;

protected:
	virtual void loadBitmaps() override;

public:
	virtual void draw(const HWND hwnd, const HDC dc) const override;
};

