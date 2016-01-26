#ifndef BOARD_H
#define BOARD_H

#include <string>

class Board{

public:
	Board(); // ctor 

	int board[81]; // holds all values for the board (accessed as 2D array)

	std::string vBoard[19]; // visual board or suduko board
	void addBlock(int row, int col, int num);  // add num to block at row/col
	void removeBlock(int row, int col);  // remove a number from row/col
	void drawBoard(); // draws the vBoard when called
	~Board(); // dtor


};


#endif
