
#ifndef CHESSPIECES
# define CHESSPIECES

#include "bitmap_image.hpp" 
#include <map>

const int boardSize = 960;
const int bSize = boardSize/ 16;
const int lSize = boardSize/ 8;

inline int getXPosPiece(int x)
{
    int xPos;

    if (x < 4)
	xPos = -(lSize * (4 - x)  - bSize);
    else 
	xPos = (lSize * (x - 4) + bSize);
    return (xPos);
}

inline int getYPosPiece(int y)
{
    int yPos;

    if (y < 4)
	yPos = (lSize * (4 - y) - bSize);
    else
	yPos = -(lSize * (y - 4) + bSize);
    return (yPos);
}

inline void rook(cartesian_canvas &board, int x, int y, int color)
{
    int xPos = getXPosPiece(x);
    int yPos = getYPosPiece(y);

    if (color = 0)
	board.pen_color(255, 255, 255);
    else
	board.pen_color(0, 0, 0);

    board.pen_width(1);
    board.fill_rectangle(xPos -bSize + bSize/5, yPos -bSize/2,
	    xPos + bSize - bSize/5, yPos -bSize + bSize /5);
    board.fill_rectangle(xPos -bSize + bSize/3, yPos -bSize/4,
	    xPos + bSize - bSize/3, yPos -bSize + bSize /2);
    board.fill_rectangle(xPos -bSize/2.5, yPos + bSize/2, 
	    xPos + bSize/2.5, yPos -bSize/4);
    board.fill_rectangle(xPos -bSize/2.5, yPos + bSize/1.5, 
	    xPos -bSize/5, yPos +bSize/2);
    board.fill_rectangle(xPos -bSize/10, yPos + bSize/1.5, 
	    xPos +bSize/10, yPos +bSize/2);
    board.fill_rectangle(xPos + bSize/5, yPos + bSize/1.5, 
	    xPos +bSize/2.5, yPos +bSize/2);
}

inline void pawn(cartesian_canvas &board, int x, int y, int color)
{
    int xPos = getXPosPiece(x);
    int yPos = getYPosPiece(y);

    if (color = 0)
	board.pen_color(255, 255, 255);
    else
	board.pen_color(0, 0, 0);

    board.pen_width(1);
    board.fill_rectangle(xPos -bSize + bSize/5, yPos -bSize/2,
	    xPos + bSize - bSize/5, yPos -bSize + bSize /5);
    board.fill_rectangle(xPos -bSize + bSize/3, yPos -bSize/4,
	    xPos + bSize - bSize/3, yPos -bSize + bSize /2);
    board.fill_rectangle(xPos -bSize/5, yPos + bSize/4, 
	    xPos + bSize/5, yPos -bSize/4);
    board.fill_circle(xPos, yPos + bSize/4, bSize/4);
}

inline void knight(cartesian_canvas &board, int x, int y, int color)
{
    int xPos = getXPosPiece(x);
    int yPos = getYPosPiece(y);

    if (color = 0)
	board.pen_color(255, 255, 255);
    else
	board.pen_color(0, 0, 0);

    board.pen_width(1);
    board.fill_rectangle(xPos -bSize + bSize/5, yPos -bSize/2,
	    xPos + bSize - bSize/5, yPos -bSize + bSize /5);
    board.fill_rectangle(xPos -bSize + bSize/3, yPos -bSize/4,
	    xPos + bSize - bSize/3, yPos -bSize + bSize /2);
    board.fill_rectangle(xPos -bSize/3, yPos - bSize/8, 
	    xPos + bSize/3, yPos -bSize/4);
    board.fill_rectangle(xPos -bSize/5, yPos + bSize/1.5, 
	    xPos + bSize/2, yPos - bSize / 8);
    board.fill_rectangle(xPos, yPos + bSize/1.2, 
	    xPos + bSize/3, yPos);
    ///knight mouth
    board.fill_rectangle(xPos -bSize/3, yPos + bSize/1.7, 
	    xPos + bSize/2, yPos + bSize/5);
    board.fill_rectangle(xPos -bSize/1.7, yPos + bSize/2, 
	    xPos + bSize/2, yPos + bSize/8);
}

inline void bishop(cartesian_canvas &board, int x, int y, int color)
{
    int xPos = getXPosPiece(x);
    int yPos = getYPosPiece(y);

    if (color = 0)
	board.pen_color(255, 255, 255);
    else
	board.pen_color(0, 0, 0);

    board.pen_width(1);
    board.fill_rectangle(xPos -bSize + bSize/5, yPos -bSize/2,
	    xPos + bSize - bSize/5, yPos -bSize + bSize /5);
    board.fill_rectangle(xPos -bSize + bSize/3, yPos -bSize/4,
	    xPos + bSize - bSize/3, yPos -bSize + bSize /2);
    board.fill_rectangle(xPos -bSize/6, yPos + bSize / 5, 
	    xPos + bSize/6, yPos -bSize/4);
    // neck
    board.fill_rectangle(xPos -bSize/3, yPos + bSize / 5, 
	    xPos + bSize/3, yPos +bSize/10);
    // head
    board.fill_rectangle(xPos -bSize/5, yPos + bSize / 2, 
	    xPos + bSize/5, yPos +bSize/10);
    board.fill_rectangle(xPos -bSize/15, yPos + bSize / 1.5, 
	    xPos + bSize/15, yPos +bSize/2);
}

inline void king(cartesian_canvas &board, int x, int y, int color)
{
    int xPos = getXPosPiece(x);
    int yPos = getYPosPiece(y);

    if (color = 0)
	board.pen_color(255, 255, 255);
    else
	board.pen_color(0, 0, 0);

    board.pen_width(1);
    board.fill_rectangle(xPos -bSize + bSize/5, yPos -bSize/2,
	    xPos + bSize - bSize/5, yPos -bSize + bSize /5);
    board.fill_rectangle(xPos -bSize + bSize/3, yPos -bSize/4,
	    xPos + bSize - bSize/3, yPos -bSize + bSize /2);
    // body
    board.fill_rectangle(xPos -bSize/6, yPos + bSize / 4, 
	    xPos + bSize/6, yPos -bSize/4);
    // neck
    board.fill_rectangle(xPos -bSize/4, yPos + bSize / 4, 
	    xPos + bSize/4, yPos +bSize/8);
    // head
    board.fill_rectangle(xPos -bSize/5, yPos + bSize / 2, 
	    xPos + bSize/5, yPos +bSize/8);
    board.fill_rectangle(xPos -bSize/10, yPos + bSize / 1.8, 
	    xPos + bSize/10, yPos +bSize/2);
    // cross
    board.fill_rectangle(xPos - bSize/20, yPos + bSize / 1.2,
	    xPos + bSize/20, yPos + bSize / 1.8);
    board.fill_rectangle(xPos - bSize/8, yPos + bSize / 1.3,
	    xPos + bSize/8, yPos + bSize / 1.4);

}

inline void queen(cartesian_canvas &board, int x, int y, int color)
{
    int xPos = getXPosPiece(x);
    int yPos = getYPosPiece(y);

    if (color = 0)
	board.pen_color(255, 255, 255);
    else
	board.pen_color(0, 0, 0);

    board.pen_width(1);
    board.fill_rectangle(xPos -bSize + bSize/5, yPos -bSize/2,
	    xPos + bSize - bSize/5, yPos -bSize + bSize /5);
    board.fill_rectangle(xPos -bSize + bSize/3, yPos -bSize/4,
	    xPos + bSize - bSize/3, yPos -bSize + bSize /2);
    // body
    board.fill_rectangle(xPos -bSize/6, yPos + bSize / 4, 
	    xPos + bSize/6, yPos -bSize/4);
    // neck
    board.fill_rectangle(xPos -bSize/4, yPos + bSize / 4, 
	    xPos + bSize/4, yPos +bSize/8);
    // head
    board.fill_rectangle(xPos -bSize/5, yPos + bSize / 2, 
	    xPos + bSize/5, yPos +bSize/8);
    board.fill_rectangle(xPos -bSize/4, yPos + bSize / 1.7, 
	    xPos + bSize/4, yPos +bSize/2);
    board.fill_rectangle(xPos -bSize/10, yPos + bSize / 1.4, 
	    xPos + bSize/10, yPos +bSize/1.7);

}

#endif
