#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Dice.h"

std::ostream& operator<< (std::ostream& out, FieldEffect f);
int main()
{
	Board board;
	Player player;
	player.setCurrentField(board.getStartingField());

	std::cout << "Press enter to roll";
	while (std::cin.get())
	{
		int roll = Dice::Roll();
		std::cout << roll << std::endl;

		for (int i = 0; i < roll; i++)
		{
			Field* tmp = player.currentField;
			player.currentField = player.currentField->nextField(player.previousField, &player.direction, player.shouldTurn);
			player.previousField = tmp;


			std::cout << typeid(*player.currentField).name() << " ";
			std::cout << player.currentField->getEffect() << std::endl;
		}
	}


	

	return 0;
}












std::ostream& operator<< (std::ostream& out, FieldEffect f)
{
	switch (f)
	{
	case FieldEffect::NONE:
		out << "None";
		break;
	case FieldEffect::O:
		out << "O";
		break;
	case FieldEffect::P:
		out << "P";
		break;
	case FieldEffect::H:
		out << "H";
		break;
	case FieldEffect::X:
		out << "X";
		break;
	case FieldEffect::S:
		out << "S";
		break;
	case FieldEffect::T:
		out << "T";
		break;
	default:
		break;
	}
	return out;
}