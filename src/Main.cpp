#include <iostream>
#include "Board.h"
#include "Player.h"

std::ostream& operator<< (std::ostream& out, FieldEffect f);
int main()
{
	Board board;
	Player player;
	player.setCurrentField(board.getStartingField());

	for (int i = 0; i < 76; i++)
	{
		Field* tmp = player.currentField;
		player.currentField = player.currentField->nextField(player.previousField, &player.direction, player.shouldTurn);
		player.previousField = tmp;


		std::cout << typeid(*player.currentField).name() << std::endl;
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