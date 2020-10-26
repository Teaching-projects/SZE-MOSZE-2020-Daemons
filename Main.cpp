#include "Unit.h"
#include "Control.h"
#include <vector>

int main(int argc,char** argv)///< Main function, returns 0 if everything OK.
{
	std::vector<std::string> args(argc);
	for(int i=0; i<argc; ++i){
		args[i] = argv[i];
	}
	try{
		Unit player1 = Unit::parseUnit(args[1]);
		Unit player2 = Unit::parseUnit(args[2]);
		player1.Fight(&player2);
		if (player1.getHp() == 0)
		{
			std::cout << player2.getName() << " wins. Remaining HP: " << player2.getHp() << std::endl;
		}
		else	
		{
			std::cout << player1.getName() << " wins. Remaining HP: " << player1.getHp() << std::endl;
		}
		
	}catch(std::exception &e){
		std::cout << "Oops, " << e.what() << std::endl;
		return 1;
	}
	

	return 0;
}