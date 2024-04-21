#include "../Main/framework.h"

Stage::Stage()
{  
}

Stage::~Stage()
{
	for (const HBITMAP& object : m_bitmaps)
	{
		DeleteObject(object);
	} 
}