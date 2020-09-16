#include "Control.h"
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

const void Control::Attack(Unit & firstplayer, Unit& secondplayer)
{
	
	int firsthp = firstplayer.GetHp();
	int secondhp = secondplayer.GetHp();
	int firstdmg = firstplayer.GetDmg();
	int seconddmg = secondplayer.GetDmg();
	std::string firstname = firstplayer.GetName();
	std::string secondname = secondplayer.GetName();
	Report(firstplayer, secondplayer);

	while (firsthp > 0 && secondhp > 0)
	{
		std::cout << firstname << " ->" << secondname << std::endl;
		//secondhp = secondhp - firstdmg;
		//secondplayer.SetHp(secondhp);
		secondplayer.TakeDamage(firstdmg);
		secondhp = secondplayer.GetHp();
		Report(firstplayer, secondplayer);
		if (secondhp > 0)
		{
			std::cout << secondname << " ->" <<   firstname << std::endl;
			//firsthp = firsthp - seconddmg;
			//firstplayer.SetHp(firsthp);
			firstplayer.TakeDamage(seconddmg);
			firsthp=firstplayer.GetHp();
			Report(firstplayer, secondplayer);
		}
	}
}

const void Control::Report(Unit firstplayer, Unit secondplayer)
{
	std::cout << firstplayer.GetName() << ":  HP: " << firstplayer.GetHp() << " Damage: " << firstplayer.GetDmg() << std::endl;
	std::cout << secondplayer.GetName() << ":  HP: " << secondplayer.GetHp() << " Damage: " << secondplayer.GetDmg() << std::endl;
}


	

