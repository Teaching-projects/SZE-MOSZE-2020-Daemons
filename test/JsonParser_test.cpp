#include "../JSON.h"
#include <gtest/gtest.h>
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <stdio.h>

double getRandomNumber(){
  std::random_device rd;
    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::seconds>(
                std::chrono::system_clock::now().time_since_epoch()
                ).count() +
            (std::mt19937::result_type)
            std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::high_resolution_clock::now().time_since_epoch()
                ).count() );

    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> distrib(1, 300);

    return distrib(gen);
}

std::string createRandomNumberOfWhitespaces(){
    std::string whitespaces = "";

    for(int i=0; i<getRandomNumber(); i++){
      whitespaces += " ";
    }

    return whitespaces;
}


TEST(JsonParserTest, string_parameter){
  double hp = getRandomNumber();
  double dmg = getRandomNumber();
  std::string testString = "{\n"+createRandomNumberOfWhitespaces()+"\"name\""+
  createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+"\"Whitespaces in Name\",\n"+
  createRandomNumberOfWhitespaces()+"\"hp\""+createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+std::to_string(hp)+",\n"+createRandomNumberOfWhitespaces()+
  "\"dmg\":"+createRandomNumberOfWhitespaces()+std::to_string(dmg)+"\n"
  +"}";
  std::map<std::string, std::string> result = JSON::parseJSON(testString);
  std::string result_name = result.get<std::string>("name");
  std::string result_hp = result.get<std::string>("hp");
  std::string result_dmg = result.get<std::string>("dmg");
  ASSERT_TRUE(result_name == "Whitespaces in Name");
  ASSERT_TRUE(result_hp == std::to_string(hp));
  ASSERT_TRUE(result_dmg == std::to_string(dmg));
}

TEST(JsonParserTest, file_parameter){
  double hp = getRandomNumber();
  double dmg = getRandomNumber();
  std::string testString = "{\n"+createRandomNumberOfWhitespaces()+"\"name\""+
  createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+"\"Mapleee\",\n"+
  createRandomNumberOfWhitespaces()+"\"hp\""+createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+std::to_string(hp)+",\n"+createRandomNumberOfWhitespaces()+
  "\"dmg\":"+createRandomNumberOfWhitespaces()+std::to_string(dmg)+"\n"
  +"}";
  std::ofstream out("test_output.json");
  out << testString;
  out.close();
  std::map<std::string, std::string> result = JSON::parseFromFile("test_output.json");
  std::remove("test_output.json");
  std::string result_name = result.get<std::string>("name");
  std::string result_hp = result.get<std::string>("hp");
  std::string result_dmg = result.get<std::string>("dmg");
  ASSERT_TRUE(result_name == "Mapleee");
  ASSERT_TRUE(result_hp == std::to_string(hp));
  ASSERT_TRUE(result_dmg == std::to_string(dmg));
}

TEST(JsonParserTest, istream_parameter){
  double hp = getRandomNumber();
  double dmg = getRandomNumber();
  std::string testString = "{\n"+createRandomNumberOfWhitespaces()+"\"name\""+
  createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+"\"Mapleee\",\n"+
  createRandomNumberOfWhitespaces()+"\"hp\""+createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+std::to_string(hp)+",\n"+createRandomNumberOfWhitespaces()+
  "\"dmg\":"+createRandomNumberOfWhitespaces()+std::to_string(dmg)+"\n"
  +"}";
  std::ofstream out("test_output.json");
  out << testString;
  out.close();
  std::filebuf fb;
  fb.open("test_output.json", std::ios::in);
  std::istream inputstream(&fb);
  std::map<std::string, std::string> result = JSON::parseStream(inputstream);
  std::remove("test_output.json");
  std::string result_name = result.get<std::string>("name");
  std::string result_hp = result.get<std::string>("hp");
  std::string result_dmg = result.get<std::string>("dmg");
  ASSERT_TRUE(result_name == "Mapleee");
  ASSERT_TRUE(result_hp == std::to_string(hp));
  ASSERT_TRUE(result_dmg == std::to_string(dmg));
}

TEST(JsonParserTest, wrong_input){
  double hp = getRandomNumber();
  double dmg = getRandomNumber();
  std::string testString = "{\n"+createRandomNumberOfWhitespaces()+"\"nameee\""+
  createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+"\"Mapleee\",\n"+
  createRandomNumberOfWhitespaces()+"\"hp\""+createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+std::to_string(hp)+",\n"+createRandomNumberOfWhitespaces()+
  "\"dmg\":"+createRandomNumberOfWhitespaces()+std::to_string(dmg)+"\n"
  +"}";
  std::ofstream out("test_output.json");
  out << testString;
  out.close();
  std::filebuf fb;
  fb.open("test_output.json", std::ios::in);
  std::istream inputstream(&fb);
  ASSERT_THROW(JSON::parseStream(inputstream), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
