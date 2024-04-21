#include "../Main/framework.h"

LobbyStage::LobbyStage()
{
    loadBitmaps();
}

LobbyStage::~LobbyStage()
{
}

void LobbyStage::loadBitmaps()
{
    HBITMAP bitmap;
    bitmap = (HBITMAP)LoadImage(NULL, TEXT("Resources/Login/testOtherBackground.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    m_bitmaps.emplace_back(bitmap);
}

void LobbyStage::draw(const HWND hwnd, const HDC dc) const
{
    RECT windowSize;
    GetClientRect(hwnd, &windowSize);

    HDC memoryDc = CreateCompatibleDC(dc);

    HBITMAP oldBitmap = (HBITMAP)SelectObject(memoryDc, m_bitmaps[0]);
    BITMAP bitmapInformation;
    GetObject(m_bitmaps[0], sizeof(BITMAP), &bitmapInformation);
    StretchBlt(dc, 0, 0, windowSize.right, windowSize.bottom, memoryDc, 0, 0, bitmapInformation.bmWidth, bitmapInformation.bmHeight, SRCCOPY);
    SelectObject(memoryDc, oldBitmap);

    DeleteDC(memoryDc);
}
