#pragma once
#include <iostream>
#include "Unit.h"
class Control
{
public:
	void Attack(Unit& firstplayer, Unit& secondplayer) const;
	void Report(Unit& firstplayer, Unit& secondplayer) const;
	Control() {}

};
