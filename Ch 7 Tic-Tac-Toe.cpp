// Ch 7 Tic-Tac-Toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
void placeToken(char board[3][3], int &token, int& column, int& row);
void getLocation(char board[3][3], int &column, int &row, int& token);
void getBoardState(char board[3][3], int &token, int &state);
int checkForWinner(char board[3][3], int &token);

int main()
{
	char board[3][3];
	int column, row;
	int token = 1;
	int state;

	initializeBoard(board);

	do
	{
		displayBoard(board);
		getLocation(board, column, row, token);
		placeToken(board, token, column, row);
		getBoardState(board, token, state);
		token = (token == 1 ? 2 : 1);
	} while (state == 0);
	if (state == 1)
	{
		cout << "Player 1 has won the game.\n";
		displayBoard(board);
	}
	if (state == 2)
	{
		cout << "Player 2 has won the game.\n";
		displayBoard(board);
	}
	else if (state == 3)
	{
		cout << "There was a tie.\n";
		displayBoard(board);
	}

	return 0;
}

void initializeBoard(char board[3][3])
{
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			board[a][b] = '*';
		}
	}
}

void displayBoard(char board[3][3])
{
	int c = 1;
	cout << setw(5) << "1" << setw(4) << "2" << setw(5) << "3\n" << setw(15) << "- - - - - -\n";
	for (int a = 0; a < 3; a++)
	{
		cout << "|" << c << "|";
		for (int b = 0; b < 3; b++)
		{
			cout << setw(2) << board[a][b] << setw(2) << " ";
		}
		cout << endl;
		c++;
	}
	cout << endl;
}

void placeToken(char board[3][3], int &token, int &column, int &row)
{
	int a = row - 1;
	int b = column - 1;

	if (board[a][b] == '*')
	{
		if (token == 1)
		{
			board[a][b] = 'X';
		}
		else if (token == 2)
		{
			board[a][b] = 'O';
		}
	}
	else
	{
		cout << "This spot is already taken.\n";
	}
	
}

void getLocation(char board[3][3], int &column, int &row, int& token)
{
	cout << "Player " << token << "'s turn.\n";
	do
	{
		cout << "Please enter the row number (must be 1, 2, or 3): ";
		cin >> row;
	} while (row > 3 || row < 1);

	do
	{
		cout << "Please enter the column number (must be 1, 2, or 3): ";
		cin >> column;
	} while (column > 3 || column < 1);
}

void getBoardState(char board[3][3], int& token, int &state)
{
	state = checkForWinner(board, token);
}

int checkForWinner(char board[3][3], int& token)
{
	for (int a = 0; a < 3; a++)
	{
		if (board[a][0] == 'X' && board[a][1] == 'X' && board[a][2] == 'X') return 1;
		if (board[0][a] == 'X' && board[1][a] == 'X' && board[2][a] == 'X') return 1;
		if (board[a][0] == 'O' && board[a][1] == 'O' && board[a][2] == 'O') return 2;
		if (board[0][a] == 'O' && board[1][a] == 'O' && board[2][a] == 'O') return 2;
		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return 1;
		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return 1;
		if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return 2;
		if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return 2;
	}
	bool full = true;
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			if (board[a][b] == '*')
				full = false;
		}
	}
	if (full) return 3;
	return 0;
}