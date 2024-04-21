class Stage
{
protected:
	std::vector<HBITMAP> m_bitmaps;

protected:
	Stage();
	Stage(const Stage&) = delete;
	Stage(Stage&&) = delete;

public:
	virtual ~Stage();

protected:
	virtual void loadBitmaps() = 0;

public:
	virtual void draw(const HWND hwnd, const HDC dc) const = 0;
};

