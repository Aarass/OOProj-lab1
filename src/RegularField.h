#pragma once
#include "Field.h"
class RegularField : public Field
{
public:
	RegularField(FieldEffect effect = FieldEffect::NONE);
	Field* nextField(Field* previousField, Direction* direction, bool shouldTurn);
};

