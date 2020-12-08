 #pragma once
 #include <ostream>
 /*!
 * \struct Damage
 * 
 * \brief Damage struct
 * 
 * 
 * 
 * 
 * \author  Mesics Mátyás, Kulcsár Bence, Lázár Tamás
 * 
 * \version 5.0
 * 
 * \date 2020/12/03 11:47
 * 
 * Created on 2020/12/03 11:47
 */

 struct Damage {

            int physical; ///<physical damage of a Unit (Monster or Hero)

            int magical; ///<magical damage of a Unit

            Damage operator+(const Damage& other){
                    Damage dmgToReturn;
                    dmgToReturn.physical = this->physical + other.physical;
                    dmgToReturn.magical = this->magical + other.magical;

                    return dmgToReturn;
        }

             Damage& operator+=(const Damage& other){
                this->physical += other.physical;
                this->magical += other.magical;
                return *this;
             }

            Damage& operator*=(const Damage& other){
                this->physical *= other.physical;
                this->magical *= other.magical;
                return *this;
            }
            friend std::ostream& operator<<(std::ostream& out, const Damage& dmg){
            out<<"Physical: "<<dmg.physical<<", Magical: "<<dmg.magical;
            return out;
        }


        }; 