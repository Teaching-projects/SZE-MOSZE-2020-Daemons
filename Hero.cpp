#include "Hero.h"
#include "JSON.h"
#include <map>

Hero Hero::parse(const std::string& data){
	JSON returnedMap = JSON::parseJSON(data);
	return Hero(std::stod(returnedMap["hp"]),std::stod(returnedMap["dmg"]),returnedMap["name"],std::stod(returnedMap["attackcooldown"]));
}