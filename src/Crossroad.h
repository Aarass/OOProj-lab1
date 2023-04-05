#pragma once
#include "enums/Direction.h"
#include "Field.h"
class Crossroad : public Field
{
private:
	Field* m_left;
	bool m_shouldChangeDir;
public:
	Crossroad(FieldEffect effect = FieldEffect::NONE);
	Field* nextField(Field* previousField, Direction* direction, bool shouldTurn);

	void addLeft(Field* left);
	void shouldChangeDir();
};

