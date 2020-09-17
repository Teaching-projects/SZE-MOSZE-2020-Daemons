#include "Control.h"
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

void Control::Attack(Unit & firstplayer, Unit& secondplayer) const
{
	Report(firstplayer, secondplayer);

	while (firstplayer.getHp() > 0 && secondplayer.getHp() > 0)
	{
		std::cout << firstplayer.getName() << " ->" << secondplayer.getName() << std::endl;
		secondplayer.takeDamage(firstplayer);
		Report(firstplayer, secondplayer);
		if (secondplayer.getHp() > 0)
		{
			std::cout << secondplayer.getName() << " ->" <<   firstplayer.getName() << std::endl;
			firstplayer.takeDamage(secondplayer);
			Report(firstplayer, secondplayer);
		}
	}
}

void Control::Report(Unit& firstplayer, Unit& secondplayer) const
{
	std::cout << firstplayer.getName() << ":  HP: " << firstplayer.getHp() << " Damage: " << firstplayer.getDmg() << std::endl;
	std::cout << secondplayer.getName() << ":  HP: " << secondplayer.getHp() << " Damage: " << secondplayer.getDmg() << std::endl;
}
