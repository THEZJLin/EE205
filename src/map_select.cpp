#include "map_select.hpp"

MapSelect::MapSelect(Game* game_,Map* map_) : map(map_),
                                               game(game_) {
     //Load preset maps (functionality may be added later to get custom maps)
     loadMap("Default",DEFAULT);
     loadMap("Plains",PLAINS);
     loadMap("Forests",FORESTS);

     //Add map names to menu
     std::stringstream ss;
     for(const auto& it : maps) {
          ss << it.first << "\n";
     }
     menu.setString(ss.str());

     //Set menu parameters
     float pos = game->desktop.height * 0.8;
     float sizeX = game->desktop.width*0.5;
     float sizeY = game->desktop.height*0.04;
     txtSize = game->desktop.height*.03;

     //Set font
     font.loadFromFile(MENU_FONT);
     menu.setFont(font);

     menu.setPosition(Vector2f(pos,game->desktop.height*0.3));
     menu.setCharacterSize(txtSize);
     
     //Set selector parameters
     select.setFillColor(sf::Color(192,192,192)); //Silver
     select.setSize(Vector2f(sizeX,sizeY));
     select.setPosition(Vector2f(pos,game->desktop.height*0.3));

     pos = 0;
     it = maps.begin();

}


void MapSelect::draw() {
     game->window.clear();
     map->draw(game);
     game->window.draw(select);
     game->window.draw(menu);

}



void MapSelect::update() {
     select.setPosition(Vector2f(game->desktop.height*.8,(game->desktop.height*0.3) + pos*txtSize*(0.04/0.03)));
     map->updateTerrain(it->second);
}

     

void MapSelect::handleInput() {

     if(game->event.type == Event::KeyPressed) {

          switch(game->event.key.code) {
               case(Keyboard::Down):
                    pos++; it++;
                    //Bring selector back up to top if at very bottom
                    if(pos >= maps.size()) { pos = 0; it=maps.begin();}
                    break;
               case(Keyboard::Up):
                    pos--;
                    //Likewise
                    if(pos < 0) { pos = 0; it=maps.begin();}
                    else { it--; }
                    break;
               case(Keyboard::Return): 
                    //Start game with selected map
                    game->popState();
                    game->pushState(new Action(game, map));
                    break;
               default: 
                    break;
          }

}
}



/* ================Getters and Setters======================= */

void MapSelect::loadMap(const std::string& mapName,const std::string& path) {
     //Do not insert into map if path is invalid
     std::fstream fs;
     try{fs.open(path);} catch(const std::exception& e) { return; }

     maps.insert( {mapName, path} );
}


std::string& MapSelect::getMap(const std::string& mapName) {
     //Throws exception if map not available
     maps.at(mapName);
}

