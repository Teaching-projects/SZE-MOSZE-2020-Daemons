#include "Control.h"
#include <vector>
#include <string>
#include <sstream>
#include <cassert>


void Control::Attack(Unit& firstplayer,Unit& secondplayer)
{

	while (firstplayer.getHp() > 0 && secondplayer.getHp() > 0)
	{
		secondplayer.takeDamage(firstplayer);
		if (secondplayer.getHp() > 0)
		{
			firstplayer.takeDamage(secondplayer);
		}
	}
}
void Control::Report(const Unit& firstplayer,const Unit& secondplayer)
{
	std::cout << firstplayer.getName() << ":  HP: " << firstplayer.getHp() << " Damage: " << firstplayer.getDmg() << std::endl;
	std::cout << secondplayer.getName() << ":  HP: " << secondplayer.getHp() << " Damage: " << secondplayer.getDmg() << std::endl;
}