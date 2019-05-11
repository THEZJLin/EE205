#ifndef MAP_SELECT_HPP
#define MAP_SELECT_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include "state_man.hpp"
#include "map.hpp"
#include "paths.hpp"
#include "action.hpp"


//State to select game settings before game starts
class MapSelect : public GameState 
{
     public:
          //Constructor
          MapSelect(Game* game_,Map* map_);

          //Inherited functions
          void draw();
          void update();
          void handleInput();

          //Function to load maps
          void loadMap(const std::string& mapName,const std::string& path);

          //Function to get map from map
          std::string& getMap(const std::string& mapName);

     private:
          std::map<std::string,std::string> maps;
          std::map<std::string,std::string>::iterator it;

          sf::Text menu;
          sf::RectangleShape select;
          Font font;

          Map* map;
          Game* game;

          float txtSize;
          int pos;
          
};

#endif
