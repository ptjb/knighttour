#ifndef TOURMASTER_H
#define TOURMASTER_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>

#include "knight.h"
#include "board.h"

class tourmaster
{
	knight k;								//knight
	board d;								//board
	int t;									//number of moves take
	public:
		tourmaster(knight, board);			//constructor
		void reset();						//resets board, resets knight, sets t=0, and sets value of original position of knight on board to t
		void setknight(int,int);			//checks if (int,int) is valid position on board and sets knight position to (int,int)
		void moveknight();					//rmoves knight, increases t by 1, sets value on board of new knight position to t
		bool canmove(int,int);				//BOOL: if nummoves of knight = 0 return false, otherwise return true
		void walkabout();					//moves knight recursively until there are no remaining moves for it to make
		int walklength();					//returns value of t+1 (the number of squares visited by the knight)
		int boardval(int,int);				//returns value of board at (int,int)
};

#endif