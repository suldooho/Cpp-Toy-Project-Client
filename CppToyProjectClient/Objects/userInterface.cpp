#include "../Main/framework.h"

UserInterface::UserInterface() 
{ 
}

UserInterface::~UserInterface()
{
	for (const auto& control : m_controls)
	{
		DestroyWindow(control.second);
	}
}