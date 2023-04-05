#include "Game.h"
#define DEBUG
std::ostream& operator<< (std::ostream& out, FieldEffect f);
int main()
{
	Game game("src/assets/Text.txt", 1);
	while (std::cin.get())
		game.run();

	return 0;
}