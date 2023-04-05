#include "Player.h"

Player::Player()
	: previousField(nullptr)
	, currentField(nullptr)
	, direction(Direction::FORWARD)
	, shouldTurn(false)
{
}

void Player::setCurrentField(Field* field)
{
	currentField = field;
}
