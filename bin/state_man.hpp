//Header file for game state manager
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "map.hpp"

class Game;
class Map;

class GameState {
     public:

          Game* game;
          Map* map;
          virtual void draw() = 0;
          virtual void update() = 0;
          virtual void handleInput() = 0;
};

#endif
