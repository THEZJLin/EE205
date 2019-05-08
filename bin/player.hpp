#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "utilities.hpp"
#include <vector>

class Skills;

//Player class contains all user information (Currency, tiles owned, etc). One instance of this class is created for each player in game
class Player {
     public:
          //Constructor
          Player(faction fact_);

          //Setters
          void setSouls(float souls_);
          void addSouls(float soulsToAdd);
          void setTiles(float tiles);

          //Getters
          float getSouls();
          float getTiles();
          faction getFaction();
          std::vector<Skills*>& getSkills();

     private:
          //Player currency
          float souls;

          //Keeps track of tiles currently owned by player, if this reaches 0, player loses
          float tilesOwned;

          //Vector of skills useable by player
          std::vector<Skills*> useableSkills;
          
          //Player ID
          faction fact;

};



#endif
