//Header file for game state manager
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "map.hpp"
#include "console.hpp"

class Game;
class Map;
class Console;

class GameState {
     public:
          //Pointers to access game information
          Game* game;
          Map* map;
          Console* log;

          //Functions used by each state to draw to screen
          virtual void draw() = 0;
          virtual void update() = 0;
          virtual void handleInput() = 0;
};

#endif
