#include "action.hpp"
#include "movement.hpp"
#include "turn.hpp"

//Test state to test various game elements

Action::Action(Game* game_, Map* map_) : log(game_) {
     game = game_; 
     map = map_; 
     // ** TESTING ONLY** Set spawn points
     map->setPop(0, Christians);
     map->setPop((MAP_DIM*MAP_DIM)-1, Greeks);
     
     // **TESTING** Players
     Player player1(Christians);
     Player player2(Greeks);

     playersIngame.push_back(new Player(Christians));
     playersIngame.push_back(new Player(Greeks));

     it = playersIngame.begin();
     log.pushEntry("Push Enter to start turn");
}

void Action::draw() {
     game->window.clear();
     map->draw(game);
     log.draw();
}

void Action::update() {
}

void Action::handleInput() {
     if(game->event.type == Event::KeyPressed) {
          //Example usage of SWITCH statements to take user input
          switch(game->event.key.code) {
               //cases make use of "Console" class (in console.hpp/cpp)
               case(Keyboard::Escape): 
                    log.pushEntry("Enter to start turn");
               break;

               case(Keyboard::A):
                    log.pushEntry("Penis");
                    break;

               case(Keyboard::B):
                    log.pushEntry("Long John");
                    break;

               case(Keyboard::C):
                    game->pushState(new Movement(map, game));
                    break;

               case(Keyboard::Return):
                    game->pushState(new Turn(game, map, &log,*it));
                    it++;
                    if(it == playersIngame.end()) { it = playersIngame.begin(); }
                    break;

               default:
               log.pushEntry("Not a valid key, Dick"); 
               break;
          }
     }
          
     if(game->event.type == Event::Closed) { game->window.close(); }
}



//Deconstructor
Action::~Action() {
     //Delete player vector
     delete playersIngame[0];
     delete playersIngame[1];
}
