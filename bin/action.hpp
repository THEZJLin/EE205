#ifndef ACTION_HPP 
#define ACTION_HPP 

#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "state_man.hpp"
#include "movement.hpp"
#include "console.hpp"
#include "player.hpp"

//This class is a placeholder for testing map
class Action : public GameState {
     public:
          //constructor/deconstructor
          Action(Game* game_, Map* map_);
          ~Action();

          void draw();
          void update();
          void handleInput();

          //Vector of players in game
          vector<Player*> playersIngame;
          vector<Player*>::iterator it;

          bool loseCon(faction player);
          bool win;

     private:
          Console log;
};

#endif
