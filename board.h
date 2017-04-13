#ifndef BOARD_H
#define BOARD_H

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

class board
{
	int width, height;					//width of board, height of board
	std::vector<int> field;				//values indexed by (a,b) <-> a+width*b

	public:
		board(int,int);					//constructor for 'board' class
		void reset();					//resets board 
		void setval(int,int,int);		//sets value at (int,int) to int
		int getval(int,int);			//gets value at (int,int)
		bool checksqpos(int,int);		//checks whether (int,int) is a valid position
		bool checksqval(int,int);		//checks whether (int,int) is movable to
		//int getwidth();
		//int getheight();
		//std::vector<int> getfield();
		//board operator = (const board&);

	/*private:
		int getvallegal(int,int);*/
};

#endif