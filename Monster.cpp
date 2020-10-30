#include "Monster.h"
#include "JSON.h"
#include <map>

Monster Monster::parse(const std::string& data){
	JSON returnedMap = JSON::parseJSON(data);
	return Monster(std::stod(returnedMap["hp"]),std::stod(returnedMap["dmg"]),returnedMap["name"],std::stod(returnedMap["attackcooldown"]));
}