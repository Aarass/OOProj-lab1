#include "RegularField.h"

RegularField::RegularField(FieldEffect effect)
    : Field(effect)
{
}

Field* RegularField::nextField(Field* previousField, Direction* direction, bool shouldTurn)
{
    return m_next;
}
