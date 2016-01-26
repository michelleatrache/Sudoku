#include "board.h"
#include <iostream>
#include <sstream>
using namespace std;


int main(){

	cout << "Welcome to Suduko!" << endl;
	cout << "We will now initialize the board." << endl;
	cout << "Enter a number to place that number at the specified row/column." << endl;
	cout << "To leave that row/column blank, just enter -1." << endl;
	cout << "Let's begin!" << endl;

	Board *b = new Board();

	b->drawBoard();

	// opts user to initialize the board
	for(int r = 1; r <= 9; r++){
		for(int c = 1; c <= 9; c++){
			b->drawBoard();

			cout << "Row: " << r << " Column: " << c << endl;

			int num;
			cin >> num;
			
			if(num != -1){
				b->board[r-1, c-1] = num;
				cout << "r: " << r << endl;
				cout << "c: " << c << endl;
				cout << "num: " << num << endl;
				b->addBlock(r, c, num);
			}
		}
	}


	// now board has been initialized
	// TODO: prompt for adding new numbers to board

}