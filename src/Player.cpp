#include "Player.h"

Player::Player()
	: m_previousField(nullptr)
	, m_currentField(nullptr)
	, m_direction(Direction::FORWARD)
	, m_shouldTurn(true)
	, m_alreadySteppedOnH(false)
	, m_alreadySteppedOnX(false)
	, previousField(nullptr)
	, currentField(nullptr)
	, direction(Direction::FORWARD)
	, shouldTurn(true)
	, alreadySteppedOnH(false)
	, alreadySteppedOnX(false)
{
}

void Player::setCurrentField(Field* field)
{
	currentField = field;
}

void Player::makeBackup()
{
	m_previousField = previousField;
	m_currentField = currentField;
	m_direction = direction;
	m_shouldTurn = shouldTurn;
	m_alreadySteppedOnH = alreadySteppedOnH;
	m_alreadySteppedOnX = alreadySteppedOnX;
}

void Player::undoMove()
{
	previousField = m_previousField;
	currentField = m_currentField;
	direction = m_direction;
	shouldTurn = m_shouldTurn;
	alreadySteppedOnH = m_alreadySteppedOnH;
	alreadySteppedOnX = m_alreadySteppedOnX;
}
