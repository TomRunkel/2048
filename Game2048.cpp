#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdlib.h>

#define GOAL 2048
#define ROWS 4
#define COLUMNS 4

using namespace std;

class Game
{
public:
	Game();
	~Game();
	void print();
	void newTwo();
	bool keyInput(int key);
	bool checkDefeat();
	bool checkVictory();
private:
	int body[ROWS][COLUMNS];
	bool up(bool test);
	bool down(bool test);
	bool left(bool test);
	bool right(bool test);
};

void Game::print()
{
	system("CLS");
	cout << "\t**************************" << endl;
	cout << "\t*******    2048    *******" << endl;
	cout << "\t**************************" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		cout << "\t";
		for (int j = 0; j < COLUMNS; j++)
		{
			cout << body[i][j];
			if (j != COLUMNS) cout << "\t";
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "\t    (press q to quit)" << endl;
}

void Game::newTwo()
{

	srand(time(0));
	int position = rand() % (ROWS * COLUMNS);
	for  (int i = 0; body[position / ROWS][position % COLUMNS] != 0; i++)
	{
		position = (position + 1) % (ROWS * COLUMNS);

	}
	body[position / ROWS][position % COLUMNS] = 2;
}

bool Game::keyInput(int key)
{
	if (key == 72) return up(false);
	if (key == 80) return down(false);
	if (key == 75) return left(false);
	if (key == 77) return right(false);
	if (key == 'q') exit(0);
}

bool Game::checkDefeat()
{
	return (!(up(true) || down(true)) || left(true) || right(true)));
}

bool Game::checkVictory()
{
	for (int row = 0; row < ROWS - 1; row++)
	{
		for (int col = 0; col < COLUMNS - 1; col++)
		{
			if (body[row][col] == 2048) return true;
		}
	}
	return false;
}

bool Game::up(bool test)
{
	bool success = false;
	for (int i = 0; i < ROWS; i++)
	{
		for (int row = 0; row < ROWS - 1; row++)
		{
			for (int col = 0; col < COLUMNS; col++)
			{
				if (body[row][col] == 0 && body[row+1][col] != 0)
				{
					success = true;
					if (test == true) return success;
					body[row][col] = body[row + 1][col];
					body[row + 1][col] = 0;
				} 
			}
		}
	}
	for (int row = 0; row < ROWS - 1; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (body[row][col] == body[row + 1][col] && body[row][col] != 0)
			{
				success = true;
				if (test == true) return success;
				body[row][col] = body[row][col] * 2;
				for (int i = row + 1; i < ROWS-1; i++)
				{
					if (i < ROWS - 2) body[i][col] = body[i + 1][col];
					else body[i][col] = 0;
				}
			}
		}
	}
	if (success == true) newTwo();
	return success;
}
bool Game::down(bool test)
{
	bool success = false;
	for (int i = 0; i < ROWS; i++)
	{
		for (int row = ROWS - 1; row > 0; row--)
		{
			for (int col = 0; col < COLUMNS; col++)
			{
				if (body[row][col] == 0)
				{
					success = true;
					if (test == true) return success;
					body[row][col] = body[row - 1][col];
					body[row - 1][col] = 0;
				}
			}
		}
	}
	for (int row = ROWS - 1; row > 0; row--)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (body[row][col] == body[row - 1][col] && body[row][col] != 0)
			{
				success = true;
				if (test == true) return success;
				body[row][col] = body[row][col] * 2;
				for (int i = row - 1; i >= 0; i--)
				{
					if (i > 0) body[i][col] = body[i - 1][col];
					else body[i][col] = 0;
				}
			}
		}
	}
	if (success == true) newTwo();
	return success;
}
bool Game::left(bool test)
{
	bool success = false;
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int col = 0; col < COLUMNS - 1; col++)
		{
			for (int row = 0; row < ROWS; row++)
			{
				if (body[row][col] == 0 && body[row][col + 1] != 0)
				{
					success = true;
					if (test == true) return success;
					body[row][col] = body[row][col + 1];
					body[row][col + 1] = 0;
				}
			}
		}
	}
	for (int col = 0; col < COLUMNS - 1; col++)
	{
		for (int row = 0; row < ROWS; row++)
		{
			if (body[row][col] == body[row][col + 1] && body[row][col + 1] != 0)
			{
				success = true;
				if (test == true) return success;
				body[row][col] = body[row][col] * 2;
				for (int i = col + 1; i < COLUMNS - 1; i++)
				{
					if (i < COLUMNS - 2) body[row][i] = body[row][i + 1];
					else body[row][i] = 0;
				}
			}
		}
	}
	if (success == true) newTwo();
	return success;
}
bool Game::right(bool test)
{
	bool success = false;
	for (int i = 0; i < COLUMNS; i++)
	{
		for (int col = COLUMNS - 1; col > 0; col--)
		{
			for (int row = 0; row < ROWS; row++)
			{
				if (body[row][col] == 0)
				{
					success = true;
					if (test == true) return success;
					body[row][col] = body[row][col - 1];
					body[row][col - 1] = 0;
				}
			}
		}
	}
	for (int col = COLUMNS - 1; col > 0; col--)
	{
		for (int row = 0; row < ROWS; row++)
		{
			if (body[row][col] == body[row][col - 1] && body[row][col] != 0)
			{
				success = true;
				if (test == true) return success;
				body[row][col] = body[row][col] * 2;
				for (int i = col - 1; i >= 0; i--)
				{
					if (i > 0) body[row][i] = body[row][i - 1];
					else body[row][i] = 0;
				}
			}
		}
	}
	if (success == true) newTwo();
	return success;
}

Game::Game()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			body[i][j] = 0;
		}
	}
}

Game::~Game()
{
}

int getKey();
//*********************MAIN***************************
int main()
{
	Game Game1;
	Game1.newTwo();
	Game1.print();
	for (;;)
	{
		if (Game1.keyInput(getKey()) == false)
		{
			if (Game1.checkDefeat())
			{
				cout << "You suck!";
				return 0;
			}
		}
		Game1.print();
		if (Game1.checkVictory() == true)
		{
			cout << "You are awesome!";
			return 0;
		}
	}
	return 0;
}
//****************************************************

int getKey()
{
	int key = getch();
	if ((key == 0) || (key == 224))
		key = getch();				
	return key;
}