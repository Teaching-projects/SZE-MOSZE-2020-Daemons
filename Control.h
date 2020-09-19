#pragma once
#include <iostream>
#include "Unit.h"
class Control
{
public:
	static void Attack(Unit& firstplayer, Unit& secondplayer);
	static void Report(const Unit& firstplayer,const Unit& secondplayer);
};
