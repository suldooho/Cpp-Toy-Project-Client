 #include "../Main/framework.h" 

LoginMap::LoginMap() : Map(PlayerLocation::Login)
{
	loadResources();
}

LoginMap::~LoginMap()
{ 
}

void LoginMap::loadResources()
{ 
	HBITMAP bitmap;
	bitmap = (HBITMAP)LoadImage(NULL, TEXT("Resources/testMyBackground.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	m_bitmaps.emplace_back(bitmap);
}

void LoginMap::draw()
{
}
