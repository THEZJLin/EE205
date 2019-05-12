#include "ff.hpp"


FF::FF(Map* map_, Game* game_,Console* log_) : log(log_) {
     game = game_;
     map = map_;
     log->pushEntry("Press f to end fast-forward");
}


void FF::draw() {
     game->window.clear();
     map->draw(game);
     log->draw();
}


void FF::update() {
     map->updatePop(Greeks);
     map->updatePop(Christians);
}

void FF::handleInput() {
     if(game->event.type == Event::KeyPressed) {
          if(game->event.key.code == Keyboard::F) {
               game->popState();
          }
     }
     if(game->event.type == Event::Closed) {game->window.close(); }
}
     
