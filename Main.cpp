#include "Unit.h"
#include "Control.h"
#include <vector>

int main(int argc,char** argv)///< Main function, returns 1 if everything OK.
{
	Unit* player1; ///< First player implementation
	Unit* player2; ///<  Second player implementation
	std::vector<std::string> args(argc);
	for(int i=0; i<argc; ++i){
		args[i] = argv[i];
	}

	try{ ///< First try cache block, parses the  first json file to First player or  return 1 if error happens
		 player1 = Unit::parseUnit(args[1]);
		
	}catch(std::exception &e){
		std::cout << "Oops, " << e.what() << std::endl;
		return 1;
	}

	try{///< Second try cache block, parses the second json file to Second player or delete first player and  return 1 if error happens 
		 player2 = Unit::parseUnit(args[2]);

	}
	catch(std::exception &e)
	{
		std::cout << "Oops, " << e.what() << std::endl;
		delete player1;
		return 1;
		
	}

	
		player1->Fight(player2); ///< Duel between First player and Second player, First player attacks first then Second player attacks  and if nobody dies, the atkcooldowns starts and they attack accordingly.

		if (player1->getHp() == 0) ///< Print out the player who wins the duel.
		{
			std::cout << player2->getName() << " wins. Remaining HP: " << player2->getHp() << std::endl; 
		}
		else	
		{
			std::cout << player1->getName() << " wins. Remaining HP: " << player1->getHp() << std::endl;
		}
		delete player1, player2;

	return 0;
}
