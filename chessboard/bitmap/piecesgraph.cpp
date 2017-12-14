#include "bitmap_image.hpp"

const int boardSize = 480;
const int bSize = boardSize / 16;

void pawn(cartesian_canvas &board, int x, int y, int color)
{
    int xPos = 0;
    int yPos = 0;

    if (color = 0)
	board.pen_color(255, 255, 255);
    else
	board.pen_color(0, 0, 0);

    board.pen_width(1);
    board.fill_rectangle(xPos -bSize + bSize/5, yPos -bSize/2,
	    xPos + bSize - bSize/5, yPos -bSize + bSize /5);
    board.fill_rectangle(xPos -bSize + bSize/3, yPos -bSize/4,
	    xPos + bSize - bSize/3, yPos -bSize + bSize /2);
    board.fill_rectangle(xPos -bSize/5, yPos + bSize/2, 
	    xPos + bSize/5, yPos -bSize/4);
    board.fill_circle(xPos, yPos + bSize/2, bSize/3);
}

int main()
{
    cartesian_canvas board(boardSize, boardSize);
    board.image().clear(255);
    
    pawn(board, 3, 3, 1);

    board.image().save_image("output.bmp");
}
