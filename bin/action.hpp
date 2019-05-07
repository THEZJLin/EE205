#ifndef ACTION_HPP 
#define ACTION_HPP 

#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "state_man.hpp"
#include "movement.hpp"
#include "console.hpp"

//This class is a placeholder for testing map
class Action : public GameState {
     public:
          //constructor
          Action(Game* game_, Map* map_);

          void draw();
          void update();
          void handleInput();

     private:
          Console log;
};

#endif
