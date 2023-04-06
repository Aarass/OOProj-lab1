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

	int m_k;
public:
	bool isGameOver;
	Game(const char* filePath, int numberOfPlayers, int k);
	~Game();
	void run();
	void moveCurrentPlayer(int amount);
	void print();
};

