#pragma once

#include <stdlib.h>
#include <time.h>

class Dice
{
	static unsigned int t;
public:
	static unsigned int Roll()
	{
		srand(t++);
		return rand() % 6 + 1;
	}
};
unsigned int Dice::t = time(NULL);