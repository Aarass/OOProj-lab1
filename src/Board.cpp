#include "Board.h"
#include <fstream>
#include <sstream>
#include <string>

FieldEffect charToFieldEffect(char c);
Board::Board(const char* filePath)
	: m_startingField(nullptr)
{
	std::string line;
	std::stringstream ss;
	std::ifstream fs(filePath);
	if (!fs.good()) throw;

	getline(fs, line);
	ss.str(line);


	Crossroad** crossroads = new Crossroad * [4];
	for (int i = 0; i < 4; i++)
		crossroads[i] = new Crossroad();
	crossroads[1]->shouldChangeDir();
	crossroads[3]->shouldChangeDir();

	char c;
	int emptyCount = 0;
	ss >> c;
	if (c == 'e')
		ss >> emptyCount;
	FieldEffect effect = charToFieldEffect(c);

	if (effect == FieldEffect::NONE) --emptyCount;
	Field* curr = m_startingField = m_head = new RegularField(effect);
	for (int i = 0; i < 75; i++)
	{
		if (emptyCount== 0)
		{
			ss >> c;
			if (c == 'e')
				ss >> emptyCount;
		}
		effect = charToFieldEffect(c);
		if (effect == FieldEffect::NONE) 
			--emptyCount;

		if (i == 10 || i == 25 || i == 49 || i == 63)
		{
			int j;
			switch (i)
			{
				case 10: j = 0; break;
				case 25: j = 1; break;
				case 49: j = 2; break;
				case 63: j = 3; break;
			}
			crossroads[j]->addEffect(effect);
			curr->addNext(crossroads[j]);
			curr = crossroads[j];
		}
		else
		{
			RegularField* tmp = new RegularField(effect);
			curr->addNext(tmp);
			curr = tmp;
		}

		if (effect == FieldEffect::O)
			m_startingField = curr;
	}
	curr->addNext(m_startingField);

	getline(fs, line);
	ss.str(line);
	ss.clear();
	TwoWayField *prev, *next;

	emptyCount = 0;
	ss >> c;
	if (c == 'e')
		ss >> emptyCount;
	effect = charToFieldEffect(c);

	if (effect == FieldEffect::NONE) --emptyCount;

	prev = new TwoWayField(effect);
	prev->addPrev(crossroads[0]);
	crossroads[0]->addLeft(prev);

	m_head14 = prev;

	if (effect == FieldEffect::O)
		m_startingField = prev;

	for (int i = 0; i < 13; i++)
	{
		if (emptyCount == 0)
		{
			ss >> c;
			if (c == 'e')
				ss >> emptyCount;
		}
		effect = charToFieldEffect(c);
		if (effect == FieldEffect::NONE)
			--emptyCount;

		next = new TwoWayField(effect);
		prev->addNext(next);
		next->addPrev(prev);

		prev = next;

		if (effect == FieldEffect::O)
			m_startingField = prev;
	}
	prev->addNext(crossroads[1]);
	crossroads[1]->addLeft(prev);

	getline(fs, line);
	ss.str(line);
	ss.clear();

	emptyCount = 0;
	ss >> c;
	if (c == 'e')
		ss >> emptyCount;
	effect = charToFieldEffect(c);

	if (effect == FieldEffect::NONE) --emptyCount;

	prev = new TwoWayField(effect);
	prev->addPrev(crossroads[2]);
	crossroads[2]->addLeft(prev);

	m_head13 = prev;

	if (effect == FieldEffect::O)
		m_startingField = prev;

	for (int i = 0; i < 12; i++)
	{
		if (emptyCount == 0)
		{
			ss >> c;
			if (c == 'e')
				ss >> emptyCount;
		}
		effect = charToFieldEffect(c);
		if (effect == FieldEffect::NONE)
			--emptyCount;

		next = new TwoWayField(effect);
		prev->addNext(next);
		next->addPrev(prev);
		prev = next;
		if (effect == FieldEffect::O)
			m_startingField = prev;
	}
	prev->addNext(crossroads[3]);
	crossroads[3]->addLeft(prev);
}

Board::~Board()
{
	Direction dir = Direction::FORWARD;
	Field* curr;
	Field* tmp;

	curr = m_head14;
	for (int i = 0; i < 14; i++)
	{
		tmp = curr->nextField(nullptr, &dir, 0);
		delete curr;
		curr = tmp;
	}
	curr = m_head13;
	for (int i = 0; i < 13; i++)
	{
		tmp = curr->nextField(nullptr, &dir, 0);
		delete curr;
		curr = tmp;
	}
	curr = m_head;
	for (int i = 0; i < 76; i++)
	{
		tmp = curr->nextField(nullptr, &dir, 0);
		delete curr;
		curr = tmp;
	}
}

Field* Board::getStartingField()
{
	return m_startingField;
}
Field* Board::getHead()
{
	return m_head;
}
Field* Board::getHead14()
{
	return m_head14;
}
Field* Board::getHead13()
{
	return m_head13;
}
FieldEffect charToFieldEffect(char c)
{
	switch (c)
	{
	case 'e':
		return FieldEffect::NONE;
	case 'o':
		return FieldEffect::O;
	case 'h':
		return FieldEffect::H;
	case 'x':
		return FieldEffect::X;
	case 's':
		return FieldEffect::S;
	case 't':
		return FieldEffect::T;
	case 'p':
		return FieldEffect::P;
	default:
		break;
	}
}