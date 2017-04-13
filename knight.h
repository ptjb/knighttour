#ifndef KNIGHT_H
#define KNIGHT_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
#include <time.h>

#include "board.h"

class knight
{
	//friend class board;

	std::pair<int,int> pos;						//position of knight (int,int)
	std::pair<int,int> opos;					//original position of knight (int,int)
	std::vector<std::pair<int,int> > moves;		//list of coordinates of squares it is valid to move to
	//board d;

	public:
		knight(int,int);						//constructor
		int x();								//returns x coordinate of knight
		int y();								//returns y coordinate of knight
		void reset();							//returns the knight to its original position
		void setpos(int,int);					//sets position of knight to (int,int)
		void rmove(board);						//given a board, knight performs a random valid move
		int nummoves(board,int,int);			//given a board, calculates the number of valid moves from position (int,int)
		//void boardupdate(board);
		//int kboardval(int,int);

	private:
		void findmoves(board,int,int);			//given a board, finds and stores in moves all valid moves from (int,int)
};

#endif