#include "../Main/framework.h"

UserInterface::UserInterface() : m_editLetters(L"")
{ 
}

UserInterface::~UserInterface()
{
	for (const auto& control : m_controls)
	{
		DestroyWindow(control.second);
	}
}

void UserInterface::changeEidt(const HWND hwnd)
{
	try
	{
		HWND edit = m_controls[Control::Edit];
		if (edit == NULL)
		{
			throw std::runtime_error("edit == NULL");
		}

		GetWindowText(edit, m_editLetters, getLettersMaxLength());
		SetWindowText(hwnd, m_editLetters); 
	}
	catch(const std::exception& e)
	{  
		std::cout << e.what() << std::endl;
	}
}

