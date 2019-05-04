#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
     using namespace std;
#include "SFML/Graphics.hpp"
     using namespace sf;
#include "state_man.hpp"
#include <string>

#define DEBUG 1

class GameState;
//Manages window as well as states

//enumerator of game types (used for debugging)
enum state { Start, Play, Pause };

class Game {
     public:
          //Constructor and destructor
          Game();
          ~Game();

          //Functions for manipulating current states
          void pushState(GameState* state);
          void popState();

          //Getters
          //Returns enumerator with current state
          state viewState();
          //Returns current state
          GameState* getState();
          

          //sfml window
          sf::RenderWindow window;
          sf::Event event;
          sf::VideoMode desktop;

     private:
          stack<GameState*> states;
          state current;
};
           
#endif
