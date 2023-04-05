#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Dice.h"
#define DEBUG
std::ostream& operator<< (std::ostream& out, FieldEffect f);
int main()
{
	Board board("src/assets/Text.txt");
	Player player;
	player.setCurrentField(board.getStartingField());
	player.shouldTurn = true;

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



#ifdef DEBUG
			std::cout << typeid(*player.currentField).name() << " ";
#endif
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