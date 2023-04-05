#pragma once
#include "RegularField.h"
#include "TwoWayField.h"
#include "Crossroad.h"

class Board
{
private:
	Field* m_head;
	Field* m_head14;
	Field* m_head13;
	Field* m_startingField;
public:
	Board(const char* filePath);
	~Board();
	Field* getStartingField();
};

