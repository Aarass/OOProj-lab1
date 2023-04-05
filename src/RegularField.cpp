#include "RegularField.h"

RegularField::RegularField(FieldEffect effect)
    : Field(effect)
{
}

Field* RegularField::nextField(Direction* direction, bool shouldTurn)
{
    return m_next;
}
