#pragma once
#include "Field.h"

class Player
{
public:
	Field* previousField;
	Field* currentField;
	Direction direction;
	bool shouldTurn;

	Player();
	void setCurrentField(Field* field);
};

