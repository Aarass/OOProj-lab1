#include "Game.h"
#include "Dice.h"
std::ostream& operator<< (std::ostream& out, FieldEffect f);

Game::Game(const char* filePath, int numberOfPlayers)
	: m_board(filePath)
	, m_players(nullptr)
	, m_scores(nullptr)
	, m_numberOfPlayers(numberOfPlayers)
	, m_indexOfCurrentPlayer(0)
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
	int roll = Dice::Roll();
	std::cout << roll << std::endl;
	moveCurrentPlayer(roll);

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

		std::cout << player.currentField->getEffect() << std::endl;

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
	m_indexOfCurrentPlayer = (m_indexOfCurrentPlayer + 1) % m_numberOfPlayers;
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