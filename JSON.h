
/**
 * \class JsonParser
 * 
 * \brief  JsonParser class
 * 
 * This class Parses the Json Files into data, that stored in  Unit Class
 * 
 * \author  mesmatyi, kulcsarbence, Lazar-Source
 * 
 * \version 1.0
 * 
 * \date 2020/10/026 13:09
 * 
 * Created on 2020/10/26 13:09
 */


#pragma once
#include <iostream>
#include "Unit.h"
#include <string>
#include <map>
#include <variant>
#include <fstream>
#include <algorithm>

class JSON{
private:
//! Method that find the specific character in the str parameter
    /*!
	 \param str String parameter
   \param findMe const string that the method will find in the str parameter
   \param nth int parameter that represents how many findMe string we will find (default 1)
   \return the method returns the position of the founded character 
	*/
  std::map<std::string, std::string> data;
  static int nthOccurrence(const std::string& str, const std::string& findMe, int nth);
public:
  JSON(const std::map<std::string, std::string>& dat) : data(dat){}

  bool count(const std::string& input);

  std::string operator [] (std::string key) {
    return data.find(key)->second;
  }

  template <class T>
  T get(const std::string& input){
    T toReturn = data[input];
    return toReturn;
  }
//! Method that read in the lines from the Json file
    /*!

     \return Parsed lines in a Map 
	   \param data  Json file 
	*/
  static JSON parseJSON(std::istream& data);
  //! Method that parsed the the values from the lines which he get in parameter 
   //! it will throw runtime error if there is something it cant find. For Example: name-> Name key not found
    /*!
	 \param data Parsed lines in a Map
   \return Parsed Values in a Map
	*/
  static JSON parseJSON(const std::string& data);

  static JSON parseFromFile(const std::string& data);

  class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& err) : std::runtime_error(err){}
  };
};
