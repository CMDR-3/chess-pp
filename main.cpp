#include "iostream"
#include "conio.h"

using namespace std;

const int BOARD_SIZE = 8;

char chessboard[BOARD_SIZE][BOARD_SIZE];

void drawLine(bool odd, char board[BOARD_SIZE][BOARD_SIZE], int collum)
{
	for (int iLine = 7; iLine >= 0; iLine--)
	{
		if (iLine %2 == 0)
		{
			if (odd == true)
			{
				cout << "\x1b[30;40m \x1b[39;40m" << board[collum][iLine] << "\x1b[30;40m ";
			}
			else
			{
				cout << "\x1b[37;47m \x1b[39;47m" << board[collum][iLine] << "\x1b[37;47m ";
			}
		}
		else
		{
			if (odd == true)
			{
				cout << "\x1b[37;47m \x1b[39;47m" << board[collum][iLine] << "\x1b[37;47m ";
			}
			else
			{
				cout << "\x1b[30;40m \x1b[39;40m" << board[collum][iLine] << "\x1b[30;40m ";
			}
		}
	}

	cout << "\x1b[0m" << " " << collum;
}

void clearScreen()
{
	cout << "\x1b[2J";
}

void drawBoard(char board[BOARD_SIZE][BOARD_SIZE])
{
	clearScreen();

	cout << "       Collums         " << endl;
	cout << " 7  6  5  4  3  2  1  0" << endl << endl;

	for (int iLine = 7; iLine >= 0; iLine--)
	{
		if (iLine %2 == 0)
		{
			drawLine(false, board, iLine);
		}
		else
		{
			drawLine(true, board, iLine);
		}

		cout << endl;
	}

	cout << "(M)ove (Q)uit" << endl;
}

void handleInput()
{
    bool moving = false;
    int fromRow, fromCol, toRow, toCol;

    while (true) {
		char input = NULL;

		if (moving == false)
		{
			input = _getche();
		}

        if (input == 'q' || input == 'Q') {
			clearScreen();
            break;
        } else {
            if (input == 'm' || input == 'M') {
				drawBoard(chessboard);
                std::cout << "Move from (row column): ";
                std::cin >> fromRow >> fromCol;
                std::cout << "Move to (row column): ";
                std::cin >> toRow >> toCol;
                moving = true;

				cout << "Moving from row " << fromRow << ", from collum " << fromCol << " to row " << toRow << " and to collum " << toCol << endl;

				char piece = chessboard[fromCol][fromRow];

				if (piece != ' ')
				{
					chessboard[fromCol][fromRow] = ' ';
					chessboard[toRow][toCol] = piece;
				}

				drawBoard(chessboard);

				moving = false;
				handleInput();

            } //else {
                //if (!moving) {
                //    std::cout << "Unknown input " << input << std::endl;
                //}
        }
    }
}

int main()
{
	char startingPosition[BOARD_SIZE][BOARD_SIZE] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

	// Copy the starting position to the chessboard
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            chessboard[row][col] = startingPosition[row][col];
        }
    }

	drawBoard(chessboard);

	handleInput();

	return 0;
}