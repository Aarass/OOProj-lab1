#include "Crossroad.h"

Crossroad::Crossroad(FieldEffect effect)
    : Field(effect)
    , m_left(nullptr)
    , m_shouldChangeDir(false)
{
}

Field* Crossroad::nextField(Direction* direction, bool shouldTurn)
{
    if (shouldTurn)
    {
        if (m_shouldChangeDir)
            *direction = Direction::BACKWARD;

        return m_left;
    }
    return m_next;
}

void Crossroad::addLeft(Field* left)
{
    m_left = left;
}

void Crossroad::shouldChangeDir()
{
    m_shouldChangeDir = true;
}
