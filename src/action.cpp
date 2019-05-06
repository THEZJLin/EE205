#include "action.hpp"
#include "movement.hpp"

//Test state to test various game elements

Action::Action(Game* game_, Map* map_) : log(game_) {
     game = game_; 
     map = map_; 
}

void Action::draw() {
     game->window.clear();
     for(std::vector<Square*>::iterator it=map->square.begin();it!=map->square.end();++it) {
          game->window.draw((*it)->rect);
     }
     log.draw();
}

void Action::update() {
}

void Action::handleInput() {
     if(game->event.type == Event::KeyPressed) {

          //Example usage of SWITCH statements to take user input
          switch(game->event.key.code) {
               //cases make use of "Console" class (in console.hpp/cpp)
               case(Keyboard::Return): 
                    log.pushEntry("a or b to push test messages to console, c to change states");
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

               default:
               log.pushEntry("Not a valid key, Dick"); 
               break;
          }
     }
          
     if(game->event.type == Event::Closed) { game->window.close(); }
}

