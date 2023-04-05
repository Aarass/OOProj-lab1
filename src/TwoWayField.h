#pragma once
#include "Field.h"
class TwoWayField : public Field
{
private:
	Field* m_prev;
public:
	TwoWayField(FieldEffect effect = FieldEffect::NONE);
	Field* nextField(Direction* direction, bool shouldTurn);

	void addPrev(Field* prev);
};

