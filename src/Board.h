#pragma once
#include "RegularField.h"
#include "TwoWayField.h"
#include "Crossroad.h"

class Board
{
private:
	Field* m_startingField;
public:
	Board(const char* filePath);
	Field* getStartingField();
};

