#include "../Main/framework.h"

UserInterface::UserInterface() 
{ 
}

UserInterface::~UserInterface()
{
	for (const HBITMAP& object : m_bitmaps)
	{
		DeleteObject(object);
	}

	for (const auto& control : m_controls)
	{
		DestroyWindow(control.second);
	}
}