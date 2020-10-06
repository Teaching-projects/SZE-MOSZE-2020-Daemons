#pragma once
#include <iostream>
#include "Unit.h"
#include <string>
#include <map>
#include <variant>
#include <fstream>
#include <algorithm>

class JsonParser{
private:
public:
  static std::map<std::string, std::string> parseJSON(std::istream& data);
  static std::map<std::string, std::string> parseJSON(const std::string& data);
  static int nthOccurrence(const std::string& str, const std::string& findMe, int nth);
};
