#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <time.h>

#include "knight.h"
#include "board.h"
#include "tourmaster.h"

int main(int argc, char** argv)																	//input format (.exe width height pos_x pos_y)
{
	if (argc < 3)
	{
		std::cout << "\nInvalid number of arguments\nFormat X Y (xo yo)\n" << std::endl;
		return 0;
	}

	int X = atoi(argv[1]);			//Board size
	int Y = atoi(argv[2]);

	int xo = 0;						//Starting position
	int yo = 0;

	if (argc == 5)
	{
		xo = atoi(argv[3]);
		yo = atoi(argv[4]);

		if (xo < 0 || xo > X-1 || yo < 0 || yo > Y-1)
		{
			std::cout << "\nInvalid initial position\n" << std::endl;
			return 0;
		}
	}

	std::stringstream name;
	name << "solution_for_X=" << X << "_Y=" << Y << "_xo=" << xo << "_yo=" << yo << "_" << time(NULL) << ".txt";	//name of file (unique)

	std::ofstream sol;
	sol.open((name.str()).c_str());																//open file under that name

	board camelot(X, Y);																		//board sixe X*Y
	knight lancelot(xo, yo);																	//knight at (xo, yo)
	tourmaster arthur(lancelot, camelot);														//tourmaster

	while (arthur.walklength() != X*Y){															//for a completed knight's tour X*Y (all) squares must be visited

		arthur.reset();																			//reset
		arthur.walkabout();																		//random set of moves
		//std::cout << "\nhit" << std::endl;
		//std::cout << "Path of length: " << arthur.walklength() << std::endl;
	}

	for (int j=0; j<Y; j++){

		sol << "\n";

		for (int i=0; i<X; i++){

			sol << arthur.boardval(i,j) << "\t";												//print board values, solution is a series of numbers
		}																						//representing the order of visitation by the knight
	}

	sol.close();																				//close file
	return 0;
}