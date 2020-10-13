#include "JsonParser.h"

std::map<std::string, std::string> JsonParser::parseJSON(std::istream& data){
  std::string toParse;
  std::string line;
  while(std::getline(data, line)){
    toParse += line;
  }

  return JsonParser::parseJSON(toParse);
}

std::map<std::string, std::string> JsonParser::parseJSON(const std::string& data){
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
    //toParse.erase(remove_if(toParse.begin(), toParse.end(), isspace), toParse.end());
    std::string charactersToRemove = "{}";
    for(auto& ch : charactersToRemove){
      toParse.erase(std::remove(toParse.begin(), toParse.end(), ch));
    }

    std::string toProcess = toParse;

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
