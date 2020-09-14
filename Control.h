#pragma once
#include <iostream>
#include "Unit.h"
class Control
{
public:
	void Attack(Unit& firstplayer, Unit &secondplayer);
	void Report(Unit firstplayer, Unit secondplayer);
	void GameStart(Unit& firstplayer, Unit &secondplayer);
	Control() {}
	~Control() {}
};

