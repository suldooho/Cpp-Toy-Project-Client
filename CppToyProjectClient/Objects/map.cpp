#include "../Main/framework.h" 

Map::Map(PlayerLocation playerLocation) : m_playerLocation(playerLocation)
{
} 

Map::~Map()
{ 
}

PlayerLocation Map::getPlayerLocation() const
{
    return m_playerLocation;
}
