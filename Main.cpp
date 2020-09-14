#include "Unit.h"
#include "Control.h"
int main(int argc,char** argv)
{
	Control vezerles;
	std::string player_name = argv[1];
	int hp = std::atoi(argv[2]);
	int dmg = std::atoi(argv[3]);
	Unit player1(hp,dmg,player_name);
	player_name = argv[4];
	hp = std::atoi(argv[5]);
	dmg = std::atoi(argv[6]);
	Unit player2(hp,dmg,player_name);
	//vezerles.GameStart(player1,player2);
	
	vezerles.Attack(player1,player2);
	if (player1.GetHp() == 0)
	{
		std::cout << player1.GetName() << " Died " << player2.GetName() << " Wins";
	}
	else 
	{
		std::cout << player2.GetName() << " Died " << player1.GetName() << " Wins";
	}
	

	return 0;
}