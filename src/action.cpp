#include "action.hpp"
Action::Action(Game* game_, Map* map_) {
     game = game_; 
     map = map_; 
}

void Action::draw() {
     game->window.clear();
     for(std::vector<Square*>::iterator it=map->square.begin();it!=map->square.end();++it) {
          game->window.draw((*it)->rect);
     }
}

void Action::update() {
}

void Action::handleInput() {
     if(game->event.type == Event::KeyPressed) {
          game->window.close();
          }
}
