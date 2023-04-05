#pragma once
#include "Field.h"

class Player
{
private:
	Field* m_previousField;
	Field* m_currentField;
	Direction m_direction;
	bool m_shouldTurn;
	bool m_alreadySteppedOnH;
	bool m_alreadySteppedOnX;
public:
	Field* previousField;
	Field* currentField;
	Direction direction;
	bool shouldTurn;
	bool alreadySteppedOnH;
	bool alreadySteppedOnX;

	Player();
	void setCurrentField(Field* field);
	void makeBackup();
	void undoMove();
};

