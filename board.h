#ifndef BOARD_H
#define BOARD_H

#include <string>

class Board{

public:
	Board(); // ctor 

	int board[9][9]; // 2D array holds all values for the board

	std::string vBoard[19]; // visual board or suduko board
	void addBlock(int row, int col, int num);  // add num to block at row/col
	void removeBlock(int row, int col);  // remove a number from row/col
	void drawBoard(); // draws the vBoard when called
	void isWon(); // returns true if the board has been won, false otherwise
	~Board(); // dtor


};


#endif
