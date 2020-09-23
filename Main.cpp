#include "Unit.h"
#include "Control.h"
#include <vector>

int main(int argc,char** argv)
{
	std::vector<std::string> args(argc);
	for(int i=0; i<argc; ++i){
		args[i] = argv[i];
	}
	try{
		Unit* player1 = Unit::parseUnit(args[1]);
		Unit* player2 = Unit::parseUnit(args[2]);
		Control::Attack(*player1,*player2);
		if (player1->getHp() == 0)
		{
			std::cout << player2->getName() << " wins. Remaining HP: " << player2->getHp() << std::endl;
		}
		else
		{
			std::cout << player1->getName() << " wins. Remaining HP: " << player1->getHp() << std::endl;
		}
		delete player1, player2;
	}catch(std::exception &e){
		std::cout << "Oops, " << e.what() << std::endl;
		return 1;
	}

	
	

	return 0;
}
