#include "TwoWayField.h"

TwoWayField::TwoWayField(FieldEffect effect)
	: Field(effect)
	, m_prev(nullptr)
{
}

Field* TwoWayField::nextField(Direction* direction, bool shouldTurn)
{
	if (*direction == Direction::FORWARD)
		return m_next;
	return m_prev;
}

void TwoWayField::addPrev(Field* prev)
{
	m_prev = prev;
}
