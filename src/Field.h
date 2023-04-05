#pragma once
#include "enums/FieldEffect.h"
#include "enums/Direction.h"
class Field
{
protected:
	Field* m_next;
	FieldEffect m_effect;
public:
	Field(FieldEffect effect = FieldEffect::NONE);
	FieldEffect getEffect();
	void addEffect(FieldEffect effect);
	void addNext(Field* next);
	virtual Field* nextField(Field* previousField, Direction* direction, bool shouldTurn) = 0;
};

