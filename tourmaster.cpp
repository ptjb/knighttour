#include "tourmaster.h"

tourmaster::tourmaster (knight a, board b) : k(a), d(b), t(0) {								//sets t=0 and sets value on board where knight is to t

	d.setval(k.x(), k.y(), t);
	/*std::cout << "\ntm" << std::endl;*/
}

void tourmaster::reset (){																	//resets everything to state when tourmaster was constructed

	t=0;
	d.reset();
	k.reset();
	d.setval(k.x(), k.y(), t);
	return;
}

void tourmaster::setknight (int a, int b){													//checks if (a,b) is a valid board position, sets knight position
																							//and value on board there to 0
	if (!d.checksqpos(a,b)) {

		std::cout << "\nInvalid position\n" << std::endl;
		return;
	}

	d.setval(a,b,0);
	k.setpos(a,b);
	return;
}

void tourmaster::moveknight (){																//knight makes a random move, increments t, sets board value
																							//to where knight is now to t
	/*int xo = k.x(), yo = k.y();

	std::cout << "\n" << xo << "\t" << yo << std::endl;*/
	k.rmove(d);

	//std::cout << "\n" << k.x() << "\t" << k.y() << "\t" << d.getval(k.x(), k.y());
	//std::cout << "\nmk" << std::endl;
	/*if (!d.checksquare(k.x(), k.y())) {

		k.setpos(xo, yo);
		tourmaster::moveknight();
		return;
	}*/

	//std::cout << "\nwalk" << std::endl;

	t++;
	d.setval(k.x(), k.y(), t);
	
	//std::cout << "\t" << d.getval(k.x(), k.y());// << "\t" << k.kboardval(k.x(), k.y());


	//k.boardupdate(d);     //!!!!!!!!!!!

	//std::cout << "\t" << d.getval(k.x(), k.y()) << "\t" << k.kboardval(k.x(), k.y());

	//std::cout << "\n" << t << "\t" << d.getval(k.x(), k.y()) << std::endl;
	return;
}

bool tourmaster::canmove (int a, int b){													//checks if knight can move from (a,b)

	/*std::pair<int,int> trans[8];
	trans[0] = std::make_pair(a+1,b+2);
	trans[1] = std::make_pair(a+2,b+1);
	trans[2] = std::make_pair(a+2,b-1);
	trans[3] = std::make_pair(a+1,b-2);
	trans[4] = std::make_pair(a-1,b-2);
	trans[5] = std::make_pair(a-2,b-1);
	trans[6] = std::make_pair(a-2,b+1);
	trans[7] = std::make_pair(a-1,b+2);

	for (int i=0; i<8; i++){

		//std::cout << "\ncm" << std::endl;
		if (d.checksquare(trans[i].first, trans[i].second)) return true;
	}

		//if (d.checksquare(trans[0].first, trans[0].second)) return true;*/

	if (k.nummoves(d,a,b) == 0) return false;

	return true;
}

void tourmaster::walkabout (){																//moves knight until it can't move and more

	while (tourmaster::canmove(k.x(), k.y())){

		//std::cout << "\nwb" << std::endl;
		tourmaster::moveknight();
	}

	return;
}

int tourmaster::walklength () {return t+1;}													//returns number of squares visited by knight (t+1)

int tourmaster::boardval(int a, int b) {return d.getval(a,b);}								//returns value of board at (a,b)