#include "../Main/framework.h"

UserInterface::UserInterface() : m_drawed(false)
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

bool UserInterface::getDrawed()
{
	return m_drawed;
}

void UserInterface::setDrawed(bool drawed)
{
	m_drawed = drawed;
}
