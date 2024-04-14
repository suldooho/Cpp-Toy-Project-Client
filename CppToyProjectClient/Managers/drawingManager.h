class Map;

class DrawingManager
{
public:
	DrawingManager();
	DrawingManager(const DrawingManager&) = delete;
	DrawingManager(DrawingManager&&) = delete;

private:
	HBITMAP m_backBufferBitmap;
	std::unordered_map<PlayerLocation, std::unique_ptr<Map>> maps;

private:
	void loadResources();

private:
	void drawBitmap(HDC hdc, HBITMAP bitmap, int x, int y, float widthMultiply, float heightMultiply);

public: 
	void initialize();
	void setBackBufferBitmap(HWND hwnd);

public:
	void drawBackground(HWND hwnd, HDC hdc);
};

