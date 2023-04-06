#include "Game.h"
#define DEBUG
std::ostream& operator<< (std::ostream& out, FieldEffect f);
int main()
{
	int br, k;

	std::cout << "Unesite broj igraca: ";
	(std::cin >> br).get();

	std::cout << "Unesite k: ";
	(std::cin >> k).get();


	Game game("src/assets/Text.txt", br, k);
	while (!game.isGameOver)
		game.run();

	return 0;
}