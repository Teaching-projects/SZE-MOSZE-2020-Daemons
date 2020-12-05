
/**
 * \class JSON
 *
 * \brief  JSON class
 *
 * This class Parses the Json Files into data, that stored in  Unit Class
 *
 * \author  mesmatyi, kulcsarbence, Lazar-Source
 *
 * \version 5.0
 *
 * \date 2020/10/026 13:09
 *
 * Created on 2020/10/26 13:09
 */

#pragma once
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <variant>
#include <fstream>
#include <algorithm>
#include <regex>
#include <cctype>
#include <list>
#include <type_traits>


class JSON{
private:

  //! Map that stores the Json file
  std::map<std::string, std::variant<std::string, int, double>> data_map;
public:
  //!constructor
  JSON(std::map <std::string, std::variant<std::string, int, double>> data) : data_map(data){}; 
  typedef std::list<std::variant<std::string, int, double>> list;

  const int count(const std::string& input);

  //! Template to get the data from the map in different types.
  template <typename T>
	inline typename std::enable_if<std::is_same<T, JSON::list>::value, T>::type
  get(const std::string& key)
  {
  	if (!count(key)){
      throw ParseException("The given key doesnt exist in our map");
    } else{
        list toReturn;
        std::istringstream values(std::get<std::string>(data_map[key]));
        std::copy(std::istream_iterator<std::string>(values), std::istream_iterator<std::string>(), std::back_inserter(toReturn));
        return toReturn;
    }
  }

template <typename T> inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type
	get(const std::string& key){
      if (!count(key)) throw ParseException("The given key doesnt exist in our map");
      else return std::get<T>(data_map[key]);
  }
//! Method that read in the lines from the Json file
    /*!

     \return Parsed lines in a Map
	   \param data  Json file
	*/
  static const JSON parseStream(std::istream& data);
  //! Method that parsed the the values from the lines which he get in parameter
   //! it will throw runtime error if there is something it cant find. For Example: name-> Name key not found
    /*!
	 \param data Parsed lines in a Map
   \return Parsed Values in a Map
	*/
  static const JSON parseJSON(const std::string& data);
  //! Method that represents if the File can be open, or not.
   static const JSON parseFromFile(const std::string& data);


  class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& err) : std::runtime_error(err){}
  };
};
