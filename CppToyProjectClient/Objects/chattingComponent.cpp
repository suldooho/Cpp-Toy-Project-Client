#include "../Main/framework.h"

WNDPROC ChattingComponent::m_oldEditProc = NULL;

ChattingComponent::ChattingComponent(const HWND hwnd, const HINSTANCE hinstance)
{
	createControlsAndLoadBitmaps(hwnd, hinstance);
}

ChattingComponent::~ChattingComponent()
{ 
	if (m_chattingInputEdit)
	{ 
		DestroyWindow(m_chattingInputEdit);
	}

	if (m_chattingBackground)
	{
		DeleteObject(m_chattingBackground);
	}
}

LRESULT CALLBACK ChattingComponent::EditSubProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_KEYDOWN:
		switch (wparam)
		{
		case VK_RETURN:
			GameFramework::getInstance().handleKeyboardLogic(GetParent(hwnd), wparam);
			break;
			//SetFocus(hwnd);  
		}
		break;
	}

	return CallWindowProc(m_oldEditProc, hwnd, message, wparam, lparam);
}

void ChattingComponent::setChattingSize(const HWND hwnd)
{
	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	m_chattingScreenWidth = windowSize.right / 3;
	m_chattingEditHeight = 25;
	m_chattingScreenHeight = windowSize.bottom - m_chattingEditHeight;
	m_chattingScrollWidth = m_chattingEditHeight;
	m_chattingEditWidth = m_chattingScreenWidth + m_chattingScrollWidth;
}

void ChattingComponent::createControlsAndLoadBitmaps(const HWND hwnd, const HINSTANCE hinstance)
{
	setChattingSize(hwnd);

	RECT windowSize;
	GetClientRect(hwnd, &windowSize);
	
	m_scroll = CreateWindow(TEXT("scrollbar"), NULL, WS_CHILD | WS_VISIBLE | SBS_VERT, windowSize.right - m_chattingScrollWidth, 0, m_chattingScrollWidth, m_chattingScreenHeight, hwnd, (HMENU)Control::ChattingContentsScroll, hinstance, NULL);
	 
	m_chattingInputEdit = CreateWindow(TEXT("edit"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, windowSize.right - m_chattingEditWidth, m_chattingScreenHeight, m_chattingEditWidth, m_chattingEditHeight, hwnd, (HMENU)Control::Edit, hinstance, NULL);
	SendMessage(m_chattingInputEdit, EM_LIMITTEXT, (WPARAM)m_chattingMaxLength, 0);
	 
	m_chattingBackground = (HBITMAP)LoadImage(NULL, TEXT("Resources/Login/testMyBackground.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); 

	m_oldEditProc = (WNDPROC)SetWindowLongPtr(m_chattingInputEdit, GWLP_WNDPROC, (LONG_PTR)ChattingComponent::EditSubProc);
}

void ChattingComponent::movePosition(const HWND hwnd)
{ 
	setChattingSize(hwnd);

	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	MoveWindow(m_scroll, windowSize.right - m_chattingScrollWidth, 0, m_chattingScrollWidth, m_chattingScreenHeight, false);
	MoveWindow(m_chattingInputEdit, windowSize.right - m_chattingEditWidth, m_chattingScreenHeight, m_chattingEditWidth, m_chattingEditHeight, false);
} 

void ChattingComponent::inputChattingMessage(const HWND hwnd)
{
	WCHAR message[m_chattingMaxLength];
	GetWindowText(m_chattingInputEdit, message, m_chattingMaxLength); 

	m_communicationContents.emplace_back(message);

	RECT chattingScreenSize;
	RECT windowSize;
	GetClientRect(hwnd, &windowSize);
	chattingScreenSize.left = windowSize.right - m_chattingScreenWidth - m_chattingScrollWidth;
	chattingScreenSize.right = m_chattingScreenWidth;
	chattingScreenSize.top = 0;
	chattingScreenSize.bottom = m_chattingScreenHeight;

	InvalidateRect(hwnd, NULL, FALSE);
}

void ChattingComponent::showCommunicationContent(const HWND hwnd, const HDC dc)
{
	//RECT windowSize;
	//GetClientRect(hwnd, &windowSize);
	//
	//HDC backMemDC = CreateCompatibleDC(dc);
	//HDC MemDC = CreateCompatibleDC(dc);
	//HBITMAP backBitmap = CreateCompatibleBitmap(dc, windowSize.right, windowSize.bottom);
	//
	//HBITMAP oldBitmap = (HBITMAP)SelectObject(backMemDC, backBitmap);
	//BITMAP bitmapInformation;
	//GetObject(m_chattingBackground, sizeof(BITMAP), &bitmapInformation);
	//
	//for (const std::wstring& content : m_communicationContents) //TEST
	//{
	//	TextOut(MemDC, 0, 0, content.c_str(), static_cast<int>(content.length()));
	//}
	//
	////BitBlt(dc, windowSize.right - m_chattingScreenWidth - m_chattingScrollWidth, 0, m_chattingScreenWidth, m_chattingScreenHeight, memoryDc, 0, 0, SRCCOPY);
	//StretchBlt(backMemDC, windowSize.right - m_chattingScreenWidth - m_chattingScrollWidth, 0, m_chattingScreenWidth, m_chattingScreenHeight, MemDC, 0, 0, bitmapInformation.bmWidth, bitmapInformation.bmHeight, SRCCOPY);
	//
	//BitBlt(dc, 0, 0, windowSize.right, windowSize.bottom, backMemDC, 0, 0, SRCCOPY);
	//SelectObject(bitmapDC, oldBitmap);
	//DeleteDC(bitmapDC);
	//DeleteDC(memoryDc);



	RECT windowSize;
	GetClientRect(hwnd, &windowSize);

	HDC memoryDc = CreateCompatibleDC(dc);

	HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryDc, m_chattingBackground);
	BITMAP bitmapInformation;
	GetObject(m_chattingBackground, sizeof(BITMAP), &bitmapInformation);

	for (const std::wstring& content : m_communicationContents) //TEST
	{
		TextOut(memoryDc, 0, 0, content.c_str(), static_cast<int>(content.length()));
	}
	
	StretchBlt(dc, windowSize.right - m_chattingScreenWidth - m_chattingScrollWidth, 0, m_chattingScreenWidth, m_chattingScreenHeight, memoryDc, 0, 0, bitmapInformation.bmWidth, bitmapInformation.bmHeight, SRCCOPY);
	SelectObject(memoryDc, oldBitmap);

	DeleteDC(memoryDc);
}