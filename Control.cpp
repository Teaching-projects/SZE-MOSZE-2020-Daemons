#include "Control.h"
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

void Control::Attack(Unit & firstplayer, Unit& secondplayer)
{
	
	int firsthp = firstplayer.GetHp();
	int secondhp = secondplayer.GetHp();
	int firstdmg = firstplayer.GetDmg();
	int seconddmg = secondplayer.GetDmg();
	std::string firstname = firstplayer.GetName();
	std::string secondname = secondplayer.GetName();
	Report(firstplayer, secondplayer);

	while (firsthp != 0 && secondhp != 0)
	{
		std::cout << firstname << " ->" << secondname << std::endl;
		secondhp = secondhp - firstdmg;
		if (secondhp < 0)
		{
			secondhp = 0;
		}
		secondplayer.SetHp(secondhp);
		Report(firstplayer, secondplayer);
		if (secondhp != 0)
		{
			std::cout << secondname << " ->" <<   firstname << std::endl;
			firsthp = firsthp - seconddmg;
			if (firsthp < 0)
			{
				firsthp = 0;
			}
			firstplayer.SetHp(firsthp);
			Report(firstplayer, secondplayer);
		}
	}
}

void Control::Report(Unit firstplayer, Unit secondplayer)
{
	std::cout << firstplayer.GetName() << ":  HP: " << firstplayer.GetHp() << " Damage: " << firstplayer.GetDmg() << std::endl;
	std::cout << secondplayer.GetName() << ":  HP: " << secondplayer.GetHp() << " Damage: " << secondplayer.GetDmg() << std::endl;
}

void Control::GameStart(Unit & firstplayer, Unit & secondplayer)
{
	/*int hp,dmg;
	std::string player_stats;
	std::getline(std::cin,player_stats);
	std::vector<std::string> result;
	std::istringstream iss(player_stats); 
	for(std::string s; iss >> s; ){result.push_back(s);}

	std::stringstream(result[1]) >> hp;
	std::stringstream(result[2]) >> dmg;
	Unit player1(hp,dmg,result[0]);
	firstplayer = player1;

	std::stringstream(result[4]) >> hp;
	std::stringstream(result[5]) >> dmg;
	Unit player2(hp,dmg, result[3]);
	secondplayer = player2;*/
}
	

