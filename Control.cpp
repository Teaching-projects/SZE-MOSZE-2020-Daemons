#include "Control.h"
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

const void Control::Attack(Unit & firstplayer, Unit& secondplayer)
{
	
	int firsthp = firstplayer.getHp();
	int secondhp = secondplayer.getHp();
	int firstdmg = firstplayer.getDmg();
	int seconddmg = secondplayer.getDmg();
	std::string firstname = firstplayer.getName();
	std::string secondname = secondplayer.getName();
	Report(firstplayer, secondplayer);

	while (firsthp > 0 && secondhp > 0)
	{
		std::cout << firstname << " ->" << secondname << std::endl;
		//secondhp = secondhp - firstdmg;
		//secondplayer.SetHp(secondhp);
		secondplayer.takeDamage(firstdmg);
		secondhp = secondplayer.getHp();
		Report(firstplayer, secondplayer);
		if (secondhp > 0)
		{
			std::cout << secondname << " ->" <<   firstname << std::endl;
			//firsthp = firsthp - seconddmg;
			//firstplayer.SetHp(firsthp);
			firstplayer.takeDamage(seconddmg);
			firsthp=firstplayer.getHp();
			Report(firstplayer, secondplayer);
		}
	}
}

const void Control::Report(Unit& firstplayer, Unit& secondplayer)
{
	std::cout << firstplayer.getName() << ":  HP: " << firstplayer.getHp() << " Damage: " << firstplayer.getDmg() << std::endl;
	std::cout << secondplayer.getName() << ":  HP: " << secondplayer.getHp() << " Damage: " << secondplayer.getDmg() << std::endl;
}


	

