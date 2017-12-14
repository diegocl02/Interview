#include <iostream>

using namespace std;

char winLine(int a, int b, int c, char *board)
{
    if (board[a] != ' ' && board[a] == board[b] && board[b] == board[c])
	return (board[a]);
    else
	return ('n');
}

char checkWin(char *board)
{
    char w;

    if ((w = winLine(1, 2, 3, board)) != 'n')
	return (w);
    if ((w = winLine(4, 5, 6, board)) != 'n')
	return (w);
    if ((w = winLine(7, 8, 9, board)) != 'n')
	return (w);
    
    if ((w = winLine(1, 4, 7, board)) != 'n')
	return (w);
    if ((w = winLine(2, 5, 8, board)) != 'n')
	return (w);
    if ((w = winLine(3, 6, 9, board)) != 'n')
	return (w);

    if ((w = winLine(1, 5, 9, board)) != 'n')
	return (w);
    if ((w = winLine(3, 5, 7, board)) != 'n')
	return (w);
    else
	return ('n');
}

bool checkTie(char *board)
{
    for (int i = 1; i < 10; i++)
	if (board[i] == ' ')
	    return (false);
    return (true);
}

void printGame(char w, int *order, int n)
{
    cout << n << " ";
    for (int i = 1; i < 10; i++)
	cout << order[i] << " ";
    cout << w << endl;
}

int countTurns(char *board)
{
    int count = 1;

    for (int i = 0; i < 10; i++)
	if (board[i] == 'X' || board[i] == '0')
	    count++;
    return (count);
}

void findSolutions(char *board, int *order, char turn, int &n, int &pos)
{
    char w;

    if ((w = checkWin(board)) != 'n' || checkTie(board))
    {
	printGame(w, order, n);
	n++;
	return ;
    }
    for(int i = 1;  i < 10; i++)
    {
	if (board[i] == ' ')
	{
	    order[pos++] = i;
	    board[i] = turn;
	    if (turn == 'X') turn = '0';
	    else if (turn == '0') turn = 'X';
	    findSolutions(board, order, turn, n);
	    board[i] == ' ';
	    order[count] = 0;
	}
    }
}
    
void printInitGame()
{
    cout << "N" << "\t" << "X 0 X 0 X 0 X 0 X Win" << endl;
}

int main()
{
    int n = 1;
    int pos = 1;
    char board[10];
    int  order[10] = {0};
    char turn = 'X';

    for (int i = 0; i < 10 ; i++)
	board[i] = ' ';
    printInitGame();
    findSolutions(board, order, turn, n, pos);
}
