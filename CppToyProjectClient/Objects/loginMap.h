#pragma once
#include "../Main/framework.h"

class LoginMap : public Map
{
public:
	LoginMap();

public:
	virtual void loadResources() override;
	virtual void draw() override;
};

