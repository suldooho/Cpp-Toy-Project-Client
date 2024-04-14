#include "map.h"

Map::Map(PlayerLocation playerLocation) : m_playerLocation(playerLocation)
{
}

PlayerLocation Map::getPlayerLocation() const
{
    return m_playerLocation;
}
