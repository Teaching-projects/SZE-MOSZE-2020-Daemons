
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

class JsonParser{
private:
//! Method that find the specific character in the str parameter
    /*!
	 \param str String parameter
   \param findMe const character that the method will find in the str parameter
   \param nth 
	*/
  static int nthOccurrence(const std::string& str, const std::string& findMe, int nth);
public:
//! Method that read in the lines from the Json file
    /*!

     \return Parsed lines in a Map 
	   \param data  Json file 
	*/
  static std::map<std::string, std::string> parseJSON(std::istream& data);
  //! Method that parsed the the values from the lines which he get in parameter 
   //!it will throw runtime error if there is something it cant find. For Example: name-> Name key not found
    /*!
	 \param data Parsed lines in a Map
   \return Parsed Values in a Map
	*/
  static std::map<std::string, std::string> parseJSON(const std::string& data);
};
