#include "JSON.h"

JSON JSON::parseFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.fail())    {
        throw ParseException("Error opening file");
    }

    return parseStream(file);
}

JSON JSON::parseStream(std::istream& data){
  std::string toParse;
  std::string line;
  while(std::getline(data, line)){
    toParse += line;
  }

  return JSON::parseJSON(toParse);
}

JSON JSON::parseJSON(const std::string& data){
  try{
    std::map<std::string,std::variant<std::string, int, double>>  toReturn;
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
    while(JSON::nthOccurrence(toProcess, ",", 1) != -1){
      key = toProcess.substr(0, JSON::nthOccurrence(toProcess, ":", 1));
      key.erase(std::remove(key.begin(), key.end(), '\"'), key.end());
      value = toProcess.substr(JSON::nthOccurrence(toProcess, ":", 1)+1, JSON::nthOccurrence(toProcess, ",", 1)-JSON::nthOccurrence(toProcess, ":", 1)-1);
      value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());
      if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return std::isdigit(c);})) toReturn[key] = std::stoi(value);
      else if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return ((std::isdigit(c) || c == '.') ? true : false);})) toReturn[key] = std::stod(value);
      else toReturn[key] = value;
      toProcess = toProcess.substr(JSON::nthOccurrence(toProcess, ",", 1)+1);
      if(JSON::nthOccurrence(toProcess, ",", 1) == -1){
        key = toProcess.substr(0, JSON::nthOccurrence(toProcess, ":", 1));
        key.erase(std::remove(key.begin(), key.end(), '\"'), key.end());
        value = toProcess.substr(JSON::nthOccurrence(toProcess, ":", 1)+1, JSON::nthOccurrence(toProcess, ",", 1)-JSON::nthOccurrence(toProcess, ":", 1)-1);
        value.erase(std::remove(value.begin(), value.end(), '\"'), value.end());
        if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return std::isdigit(c);})) toReturn[key] = std::stoi(value);
        else if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return ((std::isdigit(c) || c == '.') ? true : false);})) toReturn[key] = std::stod(value);
        else toReturn[key] = value;
      }
    }
    return JSON(toReturn);
  }catch(std::exception& e){
    throw ParseException(e.what());
  }
}

int JSON::nthOccurrence(const std::string& str, const std::string& findMe, int nth)
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

unsigned int JSON::count(const std::string& input){
  return data_map.count(input);
}
