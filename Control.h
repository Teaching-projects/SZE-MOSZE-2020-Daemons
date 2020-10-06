/**
 * \class Control
 * 
 * \brief  Control class
 * 
 * This class Reports 2 players name and hp 
 * 
 * \author  mesmatyi, kulcsarbence, Lazar-Source
 * 
 * \version 1.0
 * 
 * \date 2020/10/06 16:06
 * 
 * Created on 2020/10/06 16:06
 */
#pragma once
#include <iostream>
#include "Unit.h"
class Control
{
public:
	
	static void Report(const Unit& firstplayer/**[in] The first players Unit Object */,const Unit& secondplayer/**[in] The second players Unit Object */); ///< This method Reports 2 players name and hp
};
