#include "board.h"
#include <string>
#include <iostream>

using namespace std;



Board::Board(){


	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			board[i][j] = -1; // all indexes set to -1 to represent that they are empty (no number inserted yet)
		}
	}


/* THE FOLLOWING IS A LABELLED BOARD (row/col)

	this->vBoard[0] =   "-------------------------------------";
	this->vBoard[1] =   "|11 |12 |13 |14 |15 |16 |17 |18 |19 |";
	this->vBoard[2] =   "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[3] =   "|21 |22 |23 |24 |25 |26 |27 |28 |29 |";
	this->vBoard[4] =   "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[5] =   "|31 |32 |33 |34 |35 |36 |37 |38 |39 |";
	this->vBoard[6] =   "|-----------|-----------|-----------|";
	this->vBoard[7] =   "|41 |42 |43 |44 |45 |46 |47 |48 |49 |";
	this->vBoard[8] =   "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[9] =   "|51 |52 |53 |54 |55 |56 |57 |58 |59 |";
	this->vBoard[10] =  "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[11] =  "|61 |62 |63 |64 |65 |66 |67 |68 |69 |";
	this->vBoard[12] =  "|-----------|-----------|-----------|";
	this->vBoard[13] =  "|71 |72 |73 |74 |75 |76 |77 |78 |79 |";
	this->vBoard[14] =  "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[15] =  "|81 |82 |83 |84 |85 |86 |87 |88 |89 |";	
	this->vBoard[16] =  "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[17] =  "|91 |92 |93 |94 |95 |96 |97 |98 |99 |";
	this->vBoard[18] =  "|-----------|-----------|-----------|";
*/

	this->vBoard[0] =   "-------------------------------------";
	this->vBoard[1] =   "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[2] =   "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[3] =   "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[4] =   "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[5] =   "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[6] =   "|-----------|-----------|-----------|";
	this->vBoard[7] =   "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[8] =   "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[9] =   "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[10] =  "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[11] =  "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[12] =  "|-----------|-----------|-----------|";
	this->vBoard[13] =  "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[14] =  "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[15] =  "|   |   |   |   |   |   |   |   |   |";	
	this->vBoard[16] =  "|- - - - - -|- - - - - -|- - - - - -|";
	this->vBoard[17] =  "|   |   |   |   |   |   |   |   |   |";
	this->vBoard[18] =  "|-----------|-----------|-----------|";


}


// if rowIndex = -1, then we're checking the entire row at the column index of colIndex
// if colIndex = -1, then we're checking the entire column at the row index of rowIndex
bool checkLine(Board *b, int rowIndex, int colIndex){

	bool numCheck[9];
	for(int i = 0; i < 9; i++){
		// set all indexes to false initially. change to true if this number is encountered when traversing the line
		numCheck[i] = false;
	}


	if(rowIndex == -1){
		for(int j = 0; j < 9; j++){
			// access at b->board[rowIndex, j]
			int ind = b->board[rowIndex, j];

			if(ind == -1){
				// then this square is empty (no number placed)
				return false;
			}
			else if(numCheck[ind]){
				// then the number ind is present in the line more than once
				return false;
			}
			else{
				numCheck[ind] = true;
			}
		}
	}
	else{
		for(int i = 0; i < 9; i++){
			// access at b->board[i, rowIndex]
			int ind = b->board[i, rowIndex];

			if(ind == -1){
				// then this square is empty (no number placed)
				return false;
			}
			else if(numCheck[ind]){
				// then the number ind is present in the line more than once
				return false;
			}
			else{
				numCheck[ind] = true;
			}
		}
	}

	// if reached here, this line is valid and completed
	return true;
}


// returns true if Sudoku board has been won, false otherwise
bool Board::isWon(){
	// need to check all 9 rows, all 9 columns, and all 9 3x3 boxes


	// check all 9 rows
	for(int i = 0; i < 9; i++){
		if(!checkWin(this, i, -1)) return false;
	}


	// check all 9 columns
	for(int j = 0; j < 9; j++){
		if(!checkWin(this, -1, j)) return false;
	}


	// TODO: check all 9 3x3 boxes

}



// add num to vBoard at row and col
void Board::addBlock(int row, int col, int num){

	char cNum = '0' + num;

	switch(row){
		case 1:
			vBoard[1].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 2:
			this->vBoard[3].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 3:
			this->vBoard[5].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 4:
			this->vBoard[7].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 5:
			this->vBoard[9].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 6:
			this->vBoard[11].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 7:
			this->vBoard[13].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 8:
			this->vBoard[15].at(2 + ((col-1) * 4)) = cNum;
			break;
		case 9:
			this->vBoard[17].at(2 + ((col-1) * 4)) = cNum;
	}
}


// remove the current number from vBoard at row and col
void Board::removeBlock(int row, int col){

	switch(row){
		case 1:
			this->vBoard[1].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 2:
			this->vBoard[1].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 3:
			this->vBoard[5].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 4:
			this->vBoard[7].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 5:
			this->vBoard[9].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 6:
			this->vBoard[11].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 7:
			this->vBoard[13].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 8:
			this->vBoard[15].at(2 + ((col-1) * 4)) = ' ';
			break;
		case 9:
			this->vBoard[17].at(2 + ((col-1) * 4)) = ' ';
			break;
	}
}


// draws the vBoard to the screen
void Board::drawBoard(){
	for(int i = 0; i < 19; i++){
		cout << this->vBoard[i] << endl;
	}
}

