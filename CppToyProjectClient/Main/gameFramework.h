#pragma once
#include "framework.h"

enum class PlayerLocation
{
	Login,
	Lobby,
	Playing
};

class GameFramework
{
public:
	static GameFramework& getInstance();

private:
	GameFramework();
	GameFramework(const GameFramework&) = delete;
	GameFramework(GameFramework&&) = delete;

private:
	PlayerLocation m_playerLocation;

	std::unique_ptr<class DrawingManager> m_drawingManager;

public:
	void initialize();
};

