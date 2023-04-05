#include <iostream>
#include "Board.h"

std::ostream& operator<< (std::ostream& out, FieldEffect f);
int main()
{
	Board board;

	Field* curr = board.getStartingField();
	Field* prev = nullptr;
	Direction dir = Direction::FORWARD;

	bool shouldTurn = false;
	for (int i = 0; i < 76; i++)
	{
		if (typeid(*curr) == typeid(Crossroad))
			std::cin >> shouldTurn;

		Field* tmp = curr;
		curr = curr->nextField(prev, &dir, shouldTurn);
		prev = tmp;
		std::cout << typeid(*curr).name() << std::endl;
	}

	return 0;
}
std::ostream& operator<< (std::ostream& out, FieldEffect f)
{
	switch (f)
	{
	case FieldEffect::NONE:
		out << "None" << std::endl;
		break;
	case FieldEffect::O:
		out << "O" << std::endl;
		break;
	case FieldEffect::P:
		out << "P" << std::endl;
		break;
	case FieldEffect::H:
		out << "H" << std::endl;
		break;
	case FieldEffect::X:
		out << "X" << std::endl;
		break;
	case FieldEffect::S:
		out << "S" << std::endl;
		break;
	case FieldEffect::T:
		out << "T" << std::endl;
		break;
	default:
		break;
	}
	return out;
}