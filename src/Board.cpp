#include "Board.h"

Board::Board()
	: startingField(nullptr)
{
	Crossroad** crossroads = new Crossroad * [4];
	for (int i = 0; i < 4; i++)
		crossroads[i] = new Crossroad();
	crossroads[1]->shouldChangeDir();
	crossroads[3]->shouldChangeDir();

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
	endingField = curr;
	curr->addNext(startingField);

	TwoWayField *prev, *next;

	prev = new TwoWayField();
	prev->addPrev(crossroads[0]);
	crossroads[0]->addLeft(prev);

	for (int i = 0; i < 13; i++)
	{
		next = new TwoWayField();
		prev->addNext(next);
		next->addPrev(prev);
		prev = next;
	}
	prev->addNext(crossroads[1]);
	crossroads[1]->addLeft(prev);


	prev = new TwoWayField();
	prev->addPrev(crossroads[2]);
	crossroads[2]->addLeft(prev);

	for (int i = 0; i < 12; i++)
	{
		next = new TwoWayField();
		prev->addNext(next);
		next->addPrev(prev);
		prev = next;
	}
	prev->addNext(crossroads[3]);
	crossroads[3]->addLeft(prev);
}
