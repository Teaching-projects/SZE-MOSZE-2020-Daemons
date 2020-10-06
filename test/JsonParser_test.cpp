#include "../JsonParser.h"
#include <iostream>
#include <chrono>
#include <random>

std::string createRandomNumberOfWhitespaces(){
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
    std::uniform_int_distribution<unsigned> distrib(1, 20);

    std::string whitespaces = "";

    for(int i=0; i<distrib(gen); i++){
      whitespaces += " ";
    }

    return whitespaces;
}

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
    std::uniform_real_distribution<double> distrib(1, 20000);

    return distrib(gen);
}

TEST(JsonParserTest, string_parameter){
  double hp = getRandomNumber();
  double dmg = getRandomNumber();
  std::string testString = "{\n"+createRandomNumberOfWhitespaces()+"\"name\""+
  createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+"\"Mapleee\"\n"+
  createRandomNumberOfWhitespaces()+"\"hp\""+createRandomNumberOfWhitespaces()+":"+createRandomNumberOfWhitespaces()+std::to_string(hp)+"\n"+createRandomNumberOfWhitespaces()+
  "\"dmg\":"+createRandomNumberOfWhitespaces()+std::to_string(dmg)+"\n"
  +"}";
  std::map<std::string, std::string> result = JsonParser::parseJSON(testString);
  std::string result_name = result["name"];
  std::string result_hp = result["hp"];
  std::string result_dmg = result["dmg"];
  ASSERT_TRUE(result_name == "Mapleee");
  ASSERT_TRUE(result_hp == std::to_string(hp));
  ASSERT_TRUE(result_dmg == std::to_string(dmg));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
