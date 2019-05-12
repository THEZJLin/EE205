#include "action.hpp"
#include "movement.hpp"
#include "turn.hpp"
#include "ff.hpp"

//Test state to test various game elements

Action::Action(Game* game_, Map* map_) : log(game_) {
     game = game_; 
     map = map_; 
     // ** TESTING ONLY** Set spawn points
     map->setPop(0, Christians);
     map->setPop((MAP_DIM*MAP_DIM)-1, Greeks);
     map->square[0]->rect.setFillColor(Color::Red);
     map->square[MAP_DIM*MAP_DIM-1]->rect.setFillColor(Color::Blue);
     
     // **TESTING** Players
     Player player1(Christians);
     Player player2(Greeks);

     playersIngame.push_back(new Player(Christians));
     playersIngame.push_back(new Player(Greeks));

     it = playersIngame.begin();
     log.pushEntry("Arrow keys to navigate");
     log.pushEntry("Push Enter to start turn");
     log.pushEntry("f to fast-forward");
     log.pushEntry("esc to view these instructions again");

     win = 0;
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
                    log.pushEntry("f to fast-forward");
               break;
               
               case(Keyboard::F):
                    game->pushState(new FF(map, game, &log));
                    break;

               //Easter egg
               case(Keyboard::P):
                    log.pushEntry("8=D");
                    break;


               //case(Keyboard::C):
                 //   game->pushState(new Movement(map, game, &log));
                   // break;

               case(Keyboard::Return):
                    if(win) { game->popState(); break; }
                    game->pushState(new Turn(game, map, &log,*it));
                    if(loseCon((*it)->getFaction())) { 
                         game->popState();
                         if((*it)->getFaction() == Christians) { log.clear(); log.pushEntry("Red Loses"); }
                         else { log.clear(); log.pushEntry("Blue loses"); }
                         win = 1;
                    }
                    it++;
                    if(it == playersIngame.end()) { it = playersIngame.begin(); }
                    break;

               default:
               log.pushEntry("Not a valid key"); 
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


bool Action::loseCon(faction player) {
     for(const auto& it : map->square) {
          if(it->ownedBy == player) {
               return 0;
          }
     }
     return 1;
}
