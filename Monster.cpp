#include "Monster.h"
#include "Hero.h"
#include "JSON.h"
#include <map>

Monster Monster::parse(const std::string& data){
	JSON returnedMap = JSON::parseJSON(data);
	return Monster(std::stod(returnedMap.get<std::string>("health_points")),std::stod(returnedMap.get<std::string>("damage")),returnedMap.get<std::string>("name"),std::stod(returnedMap.get<std::string>("attack_cooldown")));
	
}