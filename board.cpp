#include "board.h"

board::board (int a, int b) : width(a), height(b) {						//sets width, height and initialises the board with -1 (not yet moved on to)
																		//left-handed coords, (0,0) in top left
	board::reset();
	//std::cout << "\nboard" << std::endl;
}

void board::reset(){													//fills all elements of the value array with -1

	field.assign(width*height, -1);										
	return;
}

void board::setval(int a, int b, int c){								//sets value of position (a,b) (if valid) to c, otherwise does nothing

	if (board::checksqpos(a,b)) {
		field[a+width*b] = c;

		//std::cout << "\t" << a+width*b << "\t" << field[a+width*b];

		return;
	}
	
	abort();
}

int board::getval(int a, int b){										//returns value at (a,b) (if valid), otherwise does nothing

	if(board::checksqpos(a,b)){
		int c = field[a+width*b];
		return c;
	}
	abort();
}

bool board::checksqpos(int a, int b){									//BOOL: if (a,b) is an invalid position on the board, return false, otherwise true

	//std::cout << "\ncs" << std::endl;

	if (a<0 || a>(width-1) || b<0 || b>(height-1)) return false;
	
	//std::cout << "\ncs2" << std::endl;


	//if (board::getvallegal(a,b) != -1) return false;

	//std::cout << "\ncs3" << std::endl;

	return true;
}

bool board::checksqval(int a, int b){									//BOOL: if (a,b) has value -1 on the board, return true (it is valid to move here),
																		//otherwise return false
	//if (board::getval(a,b) != -1) std::cout << "\t" << board::getval(a,b);
	//std::cout << a << "/" << b << "/" << board::getval(a,b) << ",";


	if (board::getval(a,b) == -1) return true;

	return false;
	//return false;
}

//int board::getwidth(){return width;}

//int board::getheight(){return height;}

//std::vector<int> board::getfield(){return field;}

/*board board::operator= (const board& c){

	board e(width, height);

	e.field = c.field;
		
	return e;
}*/

/*int board::getvallegal(int a, int b){

	int c = field[a+width*b];
	return c;
}*/