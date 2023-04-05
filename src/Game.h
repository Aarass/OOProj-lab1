#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"

class Game
{
private:
	Board m_board;
	Player* m_players;
	int* m_scores;
	int m_indexOfCurrentPlayer;
	int m_numberOfPlayers;
public:
	Game(const char* filePath, int numberOfPlayers);
	~Game();
	void run();
	void moveCurrentPlayer(int amount);
};

