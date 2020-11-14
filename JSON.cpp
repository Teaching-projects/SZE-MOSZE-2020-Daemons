#include "JSON.h"

JSON JSON::parseFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.fail())    {
        throw ParseException("Error opening file");
    }

    std::smatch allMatches;
    static const std::regex fnameCheck("([\\w]*).json$");
    if(std::regex_search(filename, allMatches, fnameCheck)){
      std::map <std::string, std::variant<std::string, int, double>> toReturn = parseStream(file).data_map;
      file.close();
      return JSON(toReturn);
    }else{
      return parseJSON(filename);
    }
}

JSON JSON::parseStream(std::istream& data){
  std::string toParse;
  std::string line;
  while(std::getline(data, line)){
    toParse += line;
  }

  return parseJSON(toParse);
}

JSON JSON::parseJSON(const std::string& data){
  static const std::regex regexForParse("\\s*\"([\\w]*)\"\\s*:\\s*\"?([\\s\\w\\.]*)\"?\\s*[,}]\\s*");
  static const std::regex regexForList("\\s*\"([\\w]*)\"\\s*:\\s*\"?\\[?\\s*([\\w\\.\"?,?\\s*]*)\"?\\s*[,\\]}]");
  std::smatch allMatches;
  std::smatch allMatchesList;
  std::map <std::string, std::variant<std::string, int, double>> map_store;
  if (data.substr(0,1) != "{"){
      throw ParseException("Missing { at the start.");
  }
  else if (data.substr(data.size()-1, 1) != "}"){
      throw ParseException("Missing { at the end.");
  }

  while(std::regex_search(data, allMatches, regexForParse)){
      if (allMatches[1] == "") {
          throw ParseException("Incorrect key");
      }
      else if (allMatches[2] == "") {
          throw ParseException("Incorrect value");
      }

      else
      {
          std::string value = allMatches[2];
          if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return std::isdigit(c);})) map_store[allMatches[1]] = std::stoi(value);
          else if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return ((std::isdigit(c) || c == '.') ? true : false);})) map_store[allMatches[1]] = std::stod(value);
          else map_store[allMatches[1]] = value;
          data = allMatches.suffix().str();
      }
  }
  if(std::regex_search(data, allMatchesList, regexForList)){
      std::string values = allMatchesList[2];
      while (values.find(",")!=std::string::npos)
          values.erase(values.find(","),1);

      while(values.find("\"")!= std::string::npos)
          values.erase(values.find("\""),1);

      map_store[allMatchesList[1]]=values;
      data = allMatchesList.suffix().str();
  }
  return JSON(map_store);
}

unsigned int JSON::count(const std::string& input){
  return data_map.count(input);
}
