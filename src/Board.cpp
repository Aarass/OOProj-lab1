#include "Board.h"

Board::Board()
	: startingField(nullptr)
{
	Crossroad** crossroads = new Crossroad * [4];
	for (int i = 0; i < 4; i++)
		crossroads[i] = new Crossroad();

	Field* curr = startingField = new RegularField();
	for (int i = 0; i < 75; i++)
	{
		if (i == 10)
		{
			curr->addNext(crossroads[0]);
			curr = crossroads[0];
		}
		else if (i == 25)
		{
			curr->addNext(crossroads[1]);
			curr = crossroads[1];
		}
		else if (i == 49)
		{
			curr->addNext(crossroads[2]);
			curr = crossroads[2];
		}
		else if (i == 63)
		{
			curr->addNext(crossroads[3]);
			curr = crossroads[3];
		}
		else
		{
			RegularField* tmp = new RegularField();
			curr->addNext(tmp);
			curr = tmp;
		}
	}
	curr->addNext(startingField);

	Direction dir = Direction::FORWARD;
	curr = startingField;
	for (int i = 0; i < 76; i++)
	{
		curr = curr->nextField(&dir, false);
	}
	if (curr == startingField)
	{
		int i = 1;
	}

}
