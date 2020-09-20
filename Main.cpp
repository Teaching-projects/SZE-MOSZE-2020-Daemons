#include "Unit.h"
#include "Control.h"

int main(int argc,char** argv)
{
	std::string firstFile = argv[1];
	std::string secondFile = argv[2];
	Unit* shit = Unit::parseUnit(firstFile);
	/*std::string player_name = argv[1];
	int hp = std::atoi(argv[2]);
	int dmg = std::atoi(argv[3]);
	Unit player1(hp,dmg,player_name);
	player_name = argv[4];
	hp = std::atoi(argv[5]);
	dmg = std::atoi(argv[6]);
	Unit player2(hp,dmg,player_name);

	Control::Attack(player1,player2);
	if (player1.getHp() == 0)
	{
		std::cout << player1.getName() << " Died " << player2.getName() << " Wins\n";
	}
	else
	{
		std::cout << player2.getName() << " Died " << player1.getName() << " Wins\n";
	}
	*/

	return 0;
}
