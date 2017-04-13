#include "knight.h"

/*knight::knight (board c, int a, int b) : d(c){

	pos.first = a;
	pos.second = b;

	opos.first = a;
	opos.second =b;

	//std::cout << "\nknight" << std::endl;
}*/

knight::knight (int a, int b){								//sets position and original position of knight, and seeds the random number generator

	pos.first = a;
	pos.second = b;

	opos.first = a;
	opos.second =b;

	srand(time(NULL));

	//std::cout << "\nknight" << std::endl;
}


int knight::x () {return pos.first;}						//returns x coordinate of knight

int knight::y () {return pos.second;}						//returns y coordinate of knight

void knight::reset(){										//sets knight position to original position

	pos = opos;
	return;
}

void knight::setpos(int a, int b){							//sets knight position to (a,b)

	pos.first = a;
	pos.second = b;
	return;
}

void knight::rmove (board c){								//finds valid moves from current position and picks one to make at random,
															//then updates position to the new position
	//std::cout << "\nrm" << std::endl;

	knight::findmoves(c, pos.first, pos.second);

	//std::cout << "\t" << moves.size() << std::endl;

	if (moves.size() == 0) return;
	
	int r = rand() % moves.size();

	/*std::pair<int,int> trans[8];
	trans[0] = std::make_pair(1,2);
	trans[1] = std::make_pair(2,1);
	trans[2] = std::make_pair(2,-1);
	trans[3] = std::make_pair(1,-2);
	trans[4] = std::make_pair(-1,-2);
	trans[5] = std::make_pair(-2,-1);
	trans[6] = std::make_pair(-2,1);
	trans[7] = std::make_pair(-1,2);*/

	//for (int i=0; i<8; i++){

	//	if ()
	//}

	knight::setpos(moves[r].first, moves[r].second);
	moves.clear();

	return;	
}

int knight::nummoves(board c, int a, int b){				//finds number of valid moves from position (a,b)

	knight::findmoves(c,a,b);
	int d = moves.size();
	moves.clear();
	return d;
}

void knight::findmoves(board c, int a, int b){				//from (a,b) knight can move to one of 8 positions, those positions that are valid
															//on the grid and valid to move to (value -1) are stored
	std::pair<int,int> trans[8];
	trans[0] = std::make_pair(a+1,b+2);
	trans[1] = std::make_pair(a+2,b+1);
	trans[2] = std::make_pair(a+2,b-1);
	trans[3] = std::make_pair(a+1,b-2);
	trans[4] = std::make_pair(a-1,b-2);
	trans[5] = std::make_pair(a-2,b-1);
	trans[6] = std::make_pair(a-2,b+1);
	trans[7] = std::make_pair(a-1,b+2);

	for (int i=0; i<8; i++){

		if (c.checksqpos(trans[i].first, trans[i].second) && c.checksqval(trans[i].first, trans[i].second)) moves.push_back(trans[i]);
	}

	return;
}

/*void knight::boardupdate(board c){

	///d.c.getwidth();
	//d.height = c.getheight();
	//d.field = c.getfield();

	d=c;
	
	return;
}*/

/*int knight::kboardval(int a, int b){

	int c=d.getval(a,b);
	return c;
}*/