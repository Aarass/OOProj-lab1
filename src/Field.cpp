#include "Field.h"

Field::Field(FieldEffect effect)
	: m_next(nullptr)
	, m_effect(effect)
{
}

FieldEffect Field::getEffect()
{
	return m_effect;
}

void Field::addEffect(FieldEffect effect)
{
	m_effect = effect;
}

void Field::addNext(Field* next)
{
	m_next = next;
}
