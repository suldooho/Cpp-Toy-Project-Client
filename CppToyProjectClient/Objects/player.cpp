#include "../Main/framework.h"

Player::Player(const HWND hwnd, const HINSTANCE hinstance)
{ 
	chattingComponent = std::make_unique<ChattingComponent>(hwnd, hinstance);
}

Player::~Player()
{
}

void Player::moveComponentsPosition(const HWND hwnd)
{
	chattingComponent->movePosition(hwnd);
}

void Player::sendMessage(const HWND hwnd)
{
	chattingComponent->inputChattingMessage(hwnd);
}

void Player::draw(const HWND hwnd, const HDC dc)
{
	chattingComponent->showCommunicationContent(hwnd, dc);
}
