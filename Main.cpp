#include "Unit.h"
#include "Control.h"
#include <vector>

int main(int argc,char** argv)
{
	Unit* player1;
	Unit* player2;
	std::vector<std::string> args(argc);
	for(int i=0; i<argc; ++i){
		args[i] = argv[i];
	}

	try{
		 player1 = Unit::parseUnit(args[1]);
		
	}catch(std::exception &e){
		std::cout << "Oops, " << e.what() << std::endl;
		return 1;
	}

	try{
		 player2 = Unit::parseUnit(args[2]);

	}
	catch(std::exception &e)
	{
		std::cout << "Oops, " << e.what() << std::endl;
		delete player1;
		return 1;
		
	}

	//Control::Attack(*player1,*player2);
		player1->Fight(player2);

		if (player1->getHp() == 0)
		{
			std::cout << player2->getName() << " wins. Remaining HP: " << player2->getHp() << " atkspeed:"<<player2->getAs()<<" Nem megy Anya "<< std::endl;
		}
		else	
		{
			std::cout << player1->getName() << " wins. Remaining HP: " << player1->getHp() << " atkspeed:"<<player1->getAs()<<" Nem megy Anya "<< std::endl;
		}
		delete player1, player2;

	return 0;
}
