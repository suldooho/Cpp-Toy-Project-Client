#pragma once
#include "../Main/framework.h"

class Map
{
protected:
	const enum class PlayerLocation m_playerLocation;

protected:
	Map(PlayerLocation playerLocation);

	Map() = delete;
	Map(const Map&) = delete;
	Map(Map&&) = delete;
	 
public:
	PlayerLocation getPlayerLocation() const;

	virtual void loadResources() = 0;
	virtual void draw() = 0;
};

