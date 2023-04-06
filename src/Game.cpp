#include "Game.h"
#include "Dice.h"
std::ostream& operator<< (std::ostream& out, FieldEffect f); 
char toChar(FieldEffect f);

Game::Game(const char* filePath, int numberOfPlayers, int k)
	: m_board(filePath)
	, m_players(nullptr)
	, m_scores(nullptr)
	, m_numberOfPlayers(numberOfPlayers)
	, m_indexOfCurrentPlayer(0)
	, m_k(k)
	, isGameOver(false)
{

	m_players = new Player[m_numberOfPlayers];
	for (int i = 0; i < m_numberOfPlayers; i++)
		m_players[i].setCurrentField(m_board.getStartingField());

	m_scores = new int[m_numberOfPlayers];
	for (int i = 0; i < m_numberOfPlayers; i++)
		m_scores[i] = 0;
}

Game::~Game()
{
	delete[] m_players;
}

void Game::run()
{
	std::system("cls");
	int roll = Dice::Roll();
	//int roll; std::cin >> roll;
	std::cout << roll << std::endl;

	moveCurrentPlayer(roll);
	if (m_scores[m_indexOfCurrentPlayer] >= m_k)
	{
		std::cout << "Player " << m_indexOfCurrentPlayer + 1 << " je pobedio!";
		isGameOver = true;
		return;
	}
	std::cout << std::endl;
	print();

	m_indexOfCurrentPlayer = (m_indexOfCurrentPlayer + 1) % m_numberOfPlayers;
	std::cout << "Player " << m_indexOfCurrentPlayer + 1 << " na potezu "; std::cin.get();

	std::cout << std::endl;
}

void Game::moveCurrentPlayer(int amount)
{
	Player& player = m_players[m_indexOfCurrentPlayer];
	//Previous stats;
	player.makeBackup();
	int previousScore = m_scores[m_indexOfCurrentPlayer];


	for (int i = 0; i < amount; i++)
	{
		Field* tmp = player.currentField;
		player.currentField = player.currentField->nextField(player.previousField, &player.direction, player.shouldTurn);
		player.previousField = tmp;

		std::cout << player.currentField->getEffect() <<  " ";

		if (player.currentField->getEffect() == FieldEffect::O)
			++m_scores[m_indexOfCurrentPlayer];
	}
	int newAmount;
	switch (player.currentField->getEffect())
	{
	case FieldEffect::P:
		player.currentField = m_board.getStartingField();

		player.alreadySteppedOnH = false;
		player.alreadySteppedOnX = false;
		break;
	case FieldEffect::H:
		if (player.alreadySteppedOnH)
		{
			player.alreadySteppedOnH = false;
			moveCurrentPlayer(amount * 3);
		}
		else
		{
			player.alreadySteppedOnH = true;
			moveCurrentPlayer(amount);
		}
		player.alreadySteppedOnX = false;
		break;
	case FieldEffect::X:
		player.undoMove();
		m_scores[m_indexOfCurrentPlayer] = previousScore;

		if (player.alreadySteppedOnH)
		{
			player.alreadySteppedOnX = false;
			moveCurrentPlayer((amount / 2 + 1) / 2 + 1);
		}
		else
		{
			player.alreadySteppedOnX = true;
			moveCurrentPlayer(amount / 2 + 1);
		}

		player.alreadySteppedOnH = false;
		break;
	case FieldEffect::S:
		player.shouldTurn = true;

		player.alreadySteppedOnH = false;
		player.alreadySteppedOnX = false;
		break;
	case FieldEffect::T:
		player.shouldTurn = false;

		player.alreadySteppedOnH = false;
		player.alreadySteppedOnX = false;
		break;
	default:
		break;
	}
}

void Game::print()
{
	char mat[20][20];
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			mat[i][j] = ' ';
		}
	}
	Field* curr = m_board.getHead();
	Direction dir = Direction::FORWARD;

	for (int i = 0; i < 19; i++)
	{
		mat[i][0] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[i][0] = '0' + j + 1;


		curr = curr->nextField(nullptr, &dir, false);
	}
	for (int i = 0; i < 19; i++)
	{
		mat[19][i] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[19][i] = '0' + j + 1;

		curr = curr->nextField(nullptr, &dir, false);
	}
	for (int i = 0; i < 19; i++)
	{
		mat[19-i][19] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[19-i][19] = '0' + j + 1;

		curr = curr->nextField(nullptr, &dir, false);
	}
	for (int i = 0; i < 19; i++)
	{
		mat[0][19-i] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[0][19-i] = '0' + j + 1;

		curr = curr->nextField(nullptr, &dir, false);
	}
	curr = m_board.getHead13();
	for (int i = 0; i < 7; i++)
	{
		mat[7][18 - i] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[7][18 - i] = '0' + j + 1;

		curr = curr->nextField(nullptr, &dir, false);
	}
	for (int i = 0; i < 6; i++)
	{
		mat[1+i][12] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[1+i][12] = '0' + j + 1;

		curr = curr->nextField(nullptr, &dir, false);
	}

	curr = m_board.getHead14();
	for (int i = 0; i < 7; i++)
	{
		mat[11][1 + i] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[11][1 + i] = '0' + j + 1;

		curr = curr->nextField(nullptr, &dir, false);
	}
	for (int i = 0; i < 7; i++)
	{
		mat[12 + i][7] = toChar(curr->getEffect());

		for (int j = 0; j < m_numberOfPlayers; j++)
			if (m_players[j].currentField == curr)
				mat[12 + i][7] = '0' + j + 1;

		curr = curr->nextField(nullptr, &dir, false);
	}


	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << mat[i][j];
		}
		std::cout << std::endl;
	}
}

char toChar(FieldEffect f)
{
	switch (f)
	{
	case FieldEffect::NONE:
		return '.';
	case FieldEffect::O:
		return 'o';
	case FieldEffect::P:
		return 'p';
	case FieldEffect::H:
		return 'h';
	case FieldEffect::X:
		return 'x';
	case FieldEffect::S:
		return 's';
	case FieldEffect::T:
		return 't';
	default:
		break;
	}
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