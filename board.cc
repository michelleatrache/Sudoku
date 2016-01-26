#include "board.h"
#include <string>
#include <iostream>

using namespace std;



Board::Board(){


	for(int i = 0; i < 81; i++){
		board[i] = -1; // all indexes set to -1 to represent that they are empty (no number inserted yet)
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


void Board::drawBoard(){
	for(int i = 0; i < 19; i++){
		cout << this->vBoard[i] << endl;
	}
}

