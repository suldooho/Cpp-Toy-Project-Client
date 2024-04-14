#pragma once 

class Map
{
protected:
	const PlayerLocation m_playerLocation;

	std::vector<HBITMAP> m_bitmaps;

protected:
	Map(PlayerLocation playerLocation);

	Map() = delete;
	Map(const Map&) = delete;
	Map(Map&&) = delete;

public:
	virtual ~Map();

protected:
	virtual void loadResources() = 0;

public:
	PlayerLocation getPlayerLocation() const;

	virtual void draw() = 0;

};

