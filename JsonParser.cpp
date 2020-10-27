#include "JsonParser.h"

std::map<std::string, std::string> JsonParser::parseJSON(std::istream& data){
  std::string toParse;
  std::string line;
  while(std::getline(data, line)){
    toParse += line;
  }

  return JsonParser::parseJSON(toParse);
}

std::map<std::string, std::string > JsonParser::parseJSON(const std::string& data){
  try{
    std::map<std::string, std::string> toReturn;
    std::ifstream test(data);
    std::string toParse = "";

    if(test){
      std::string line;
      while(std::getline(test, line)){
        toParse += line + "\n";
      }
    }else{
      toParse = data;
    }
    std::string new_str;
    bool delete_spaces = true, start = false;
    for(unsigned int i = 0; i < toParse.size(); ++i) {
        if(toParse[i] == '\"') {
            start ? start = false : start = true;
            if(start) {
                delete_spaces = false;
            }
        }
        if(!start) {
            delete_spaces = true;
        }
        if(delete_spaces) {
            if(toParse[i] != ' ' && toParse[i] != '\n' && toParse[i] != '\t') {
                new_str += toParse[i];
            }
        } else {
            new_str += toParse[i];
        }

    }
    std::string charactersToRemove = "{}";
    for(auto& ch : charactersToRemove){
      new_str.erase(std::remove(new_str.begin(), new_str.end(), ch));
    }

    std::string toProcess = new_str;

    std::string key;
    std::string value;
    while(JsonParser::nthOccurrence(toProcess, ",", 1) != -1){
      key = toProcess.substr(0, JsonParser::nthOccurrence(toProcess, ":", 1));
      key.erase(std::remove(key.begin(), key.end(), '\"'), key.end());
      value = toProcess.substr(JsonParser::nthOccurrence(toProcess, ":", 1)+1, JsonParser::nthOccurrence(toProcess, ",", 1)-JsonParser::nthOccurrence(toProcess, ":", 1)-1);
      value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());
      toReturn[key] = value;
      toProcess = toProcess.substr(JsonParser::nthOccurrence(toProcess, ",", 1)+1);
      if(JsonParser::nthOccurrence(toProcess, ",", 1) == -1){
        key = toProcess.substr(0, JsonParser::nthOccurrence(toProcess, ":", 1));
        key.erase(std::remove(key.begin(), key.end(), '\"'), key.end());
        value = toProcess.substr(JsonParser::nthOccurrence(toProcess, ":", 1)+1, JsonParser::nthOccurrence(toProcess, ",", 1)-JsonParser::nthOccurrence(toProcess, ":", 1)-1);
        value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());
        toReturn[key] = value;
      }
    }
    if( toReturn.find("name") == toReturn.end()){
      throw std::runtime_error("Name key not found");
    }
    if( toReturn.find("dmg") == toReturn.end()){
      throw std::runtime_error("Dmg key not found");
    }
    if( toReturn.find("hp") == toReturn.end()){
      throw std::runtime_error("Hp key not found");
    }
    if( std::stod(toReturn["hp"]) < 0 ){
      throw std::runtime_error("Invalid hp value");
    }
    if( std::stod(toReturn["dmg"]) < 0 ){
      throw std::runtime_error("Invalid dmg value");
    }
    return toReturn;
  }catch(std::exception& e){
    throw std::runtime_error(e.what());
  }
}

int JsonParser::nthOccurrence(const std::string& str, const std::string& findMe, int nth)
{
    size_t  pos = 0;
    int     cnt = 0;

    while( cnt != nth )
    {
        pos+=1;
        pos = str.find(findMe, pos);
        if ( pos == std::string::npos )
            return -1;
        cnt++;
    }
    return pos;
}
