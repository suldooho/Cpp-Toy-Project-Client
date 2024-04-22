class ChattingComponent
{
public:
	ChattingComponent(const HWND hwnd, const HINSTANCE hinstance);
	virtual ~ChattingComponent();

	ChattingComponent() = delete;
	ChattingComponent(const ChattingComponent&) = delete;
	ChattingComponent(ChattingComponent&&) = delete;

private:
	static const unsigned int m_chattingMaxLength = 50;
	unsigned int m_chattingScreenWidth;
	unsigned int m_chattingScreenHeight;
	unsigned int m_chattingEditWidth;
	unsigned int m_chattingEditHeight;
	unsigned int m_chattingScrollWidth;

	std::vector<std::wstring> m_communicationContents;

	static WNDPROC m_oldEditProc;

	HWND m_scroll;
	HWND m_chattingInputEdit;
	HBITMAP m_chattingBackground;

private:
	void setChattingSize(const HWND hwnd);

public:
	static LRESULT CALLBACK EditSubProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
	void createControlsAndLoadBitmaps(const HWND hwnd, const HINSTANCE hinstance);
	void movePosition(const HWND hwnd);
	void inputChattingMessage(const HWND hwnd);
	void showCommunicationContent(const HWND hwnd, const HDC dc);
};