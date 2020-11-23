#include "JSON.h"

const JSON JSON::parseFromFile(const std::string& filename)
{
    std::smatch allMatches;
    static const std::regex fnameCheck("([\\w]*).json$");
    if(std::regex_search(filename, allMatches, fnameCheck)){
      std::ifstream file;
      file.open(filename);
      if(file.fail()){
        throw ParseException("File does not exist!");
      }else{
        std::map<std::string, std::variant<std::string, int, double>> toReturn = parseStream(file).data_map;
        file.close();
        return JSON(toReturn);
      }
    }else{
      return parseJSON(filename);
    }
}

const JSON JSON::parseStream(std::istream& data){
  std::string toParse = "";
  std::string line;
  while(std::getline(data, line)){
    toParse += line;
  }
  return parseJSON(toParse);
}

const JSON JSON::parseJSON(const std::string& data){
  static const std::regex regexForParse("\\s*\"([\\w-]*)\"\\s*:\\s*\"?([\\s\\w\\.-]*)\"?\\s*[,}]\\s*");
  static const std::regex regexForList("\\s*\"([\\w]*)\"\\s*:\\s*\"?\\[?\\s*([\\w\\.\"?,?\\s*]*)\"?\\s*[,\\]}]");
  std::smatch allMatches;
  std::smatch allMatchesList;
  std::map <std::string, std::variant<std::string, int, double>> map_store;
  if (data.substr(0,1) != "{"){
      throw ParseException("Missing { at the start.");
  }
  else if (data.substr(data.size()-1, 1) != "}"){
      throw ParseException("Missing } at the end.");
  }
  std::string dataTwo = data;
  while(std::regex_search(dataTwo, allMatches, regexForParse)){
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
          std::cout<<allMatches[1]<<std::endl;
          std::cout<<allMatches[2]<<std::endl;
          dataTwo = allMatches.suffix().str();
      }
  }
  if(std::regex_search(dataTwo, allMatchesList, regexForList)){
      std::string values = allMatchesList[2];
      while (values.find(",")!=std::string::npos)
          values.erase(values.find(","),1);

      while(values.find("\"")!= std::string::npos)
          values.erase(values.find("\""),1);

      map_store[allMatchesList[1]]=values;
      dataTwo = allMatchesList.suffix().str();
  }
  return JSON(map_store);
}

const int JSON::count(const std::string& input){
  return ((data_map.find(input) != data_map.end()) ? 1 : 0);
}
