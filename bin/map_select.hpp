#ifndef MAP_SELECT_HPP
#define MAP_SELECT_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <sstream>
#include <string>
#include "state_man.hpp"
#include "map.hpp"


//State to select game settings before game starts
class MapSelect : public GameState 
{
     public:
          //Constructor
          MapSelect(Map* map_);

          //Function to load maps
          void loadMap(const std::string& mapName,const std::string& path);

          //Function to get map from map
          std::string& getMap(const std::string& mapName);

     private:
          std::map<std::string,std::string> maps;
          sf::Text menu;
          sf::RectangleShape select;

          Map* map;
          
};

#endif
