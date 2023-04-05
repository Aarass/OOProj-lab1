#pragma once
#include "RegularField.h"
#include "TwoWayField.h"
#include "Crossroad.h"

class Board
{
private:
	Field* m_startingField;
	Field* m_endingField;
public:
	Board();
	Field* getStartingField();
};

