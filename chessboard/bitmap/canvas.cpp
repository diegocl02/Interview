
#include "bitmap_image.hpp"
#include "chesspieces.hpp"
#include <SDL.h>

int getXPosBoard(int x)
{
    int xPos;

    if (x < 4)
	xPos = -(lSize * (4 - x));
    else 
	xPos = (lSize * (x - 4));
    return (xPos);
}

int getYPosBoard(int y)
{
    int yPos;

    if (y < 4)
	yPos = (lSize * (4 - y));
    else
	yPos = -(lSize * (y - 4));
    return (yPos);
}

int switchBoardSqrColor(cartesian_canvas &board, int xPos, int yPos, int flag)
{
    board.pen_width(1);
    
    if (flag)
    {
	board.pen_color(47, 53, 132);
	board.fill_rectangle(xPos, yPos , xPos + lSize, yPos + lSize);
	flag = 0;
    }
    else
    {
	board.pen_color(101, 105, 165);
	board.fill_rectangle(xPos, yPos, xPos + lSize, yPos + lSize);
	flag = 1;
    }
    return (flag);
}

void createBoard(cartesian_canvas &board)
{
    int flag = 1;
    int xPos, yPos;

    board.pen_width(1);

    for (int i = 0; i < 9; i++)
    {
	for(int j = 0; j < 8; j++)
	{
	    int yPos = getYPosBoard(i);
	    int xPos = getXPosBoard(j);
	    flag = switchBoardSqrColor(board, xPos, yPos, flag);
	}
	flag = (flag > 0) ? 0 : 1;
    }
}

void drawPiece(char c, cartesian_canvas &board, int x, int y)
{
    if(c == 'p')
	pawn(board, x, y, 1);
    else if(c == 'P')
	pawn(board, x, y, 0);
    else if(c == 'r')
	rook(board, x, y, 1);
    else if(c == 'R')
	rook(board, x, y, 0);
    else if(c == 'b')
	bishop(board, x, y, 1);
    else if(c == 'B')
	bishop(board, x, y, 0);
    else if(c == 'n')
	knight(board, x, y, 1);
    else if(c == 'N')
	knight(board, x, y, 0);
    else if(c == 'q')
	queen(board, x, y, 1);
    else if(c == 'Q')
	queen(board, x, y, 0);
    else if(c == 'k')
	king(board, x, y, 1);
    else if(c == 'K')
	king(board, x, y, 0);
}

bool isPiece(char c)
{
    if (c == 'p' || c == 'P' || c == 'r' || c == 'R' || c == 'b' || c == 'B' || c == 'n' || c == 'N'
	    || c == 'q' || c == 'Q' || c == 'k' || c == 'K')
	return (true);
    else
	return (false);
}

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
	return (true);
    else
	return (false);
}

void drawChessBoard(std::string initPosition)
{
    int x,y;

    cartesian_canvas board(boardSize, boardSize);
    board.image().clear(255);
    createBoard(board);

    x = y = 0;
    for (int i = 0; i < initPosition.size(); i++)
    {
	if (x >= 8)
	    x = 0;
	if (isPiece(initPosition[i]))
	{
	    drawPiece(initPosition[i], board, x, y);
	    x++;
	}
	else if (isNumber(initPosition[i]))
	{
	    x = x + initPosition[i] - '0';
	}
	else if (initPosition[i] == '/')
	{
	    y++;
	}
    }
    board.image().save_image("output.bmp");
}

void openBMP()
{
    SDL_Event event;
    SDL_Window *window = NULL;
    SDL_Surface *windowSurface = NULL;
    SDL_Surface *imageSurface = NULL;
    bool isRunning = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
	std::cout << "Error: " << SDL_GetError() << std::endl;
    else
    {
	window = SDL_CreateWindow("Chessboad", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, boardSize, boardSize, SDL_WINDOW_SHOWN);
	if (window == NULL)
	    std::cout << "Error: " << SDL_GetError() << std::endl;
	else
	{
	    windowSurface = SDL_GetWindowSurface(window);
	    imageSurface = SDL_LoadBMP("output.bmp");

	    if (imageSurface == NULL)
		std::cout << "Error" << SDL_GetError() << std::endl;
	    else
		while (isRunning)
		{
		    while (SDL_PollEvent(&event) != 0)
		    {
			if (event.type == SDL_QUIT)
			    isRunning = false;
		    }
		    SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
		    SDL_UpdateWindowSurface(window);
		}
	}
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(void)
{
    std::string input;

    std::cout << "Enter the chess pattern you want to show:" << std::endl;
    std::cin >> input;
    drawChessBoard(input);
    openBMP();
    return (0);
}
