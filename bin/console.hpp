#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include "game.hpp"

//Size of title
#define TSIZE resY * 0.05

class Game;

//This class creates a "text log" on the right side of the screen
//Log displays messages such as, "Building was placed" or "Turn ended"
//Class utilizes a deque to store messages
class Console {
     public:
          //Constructor, game object used to determine screen resolution
          Console(Game* game_);

          //Used to draw to game window
          void draw();

          //Used to push a message onto the log
          void pushEntry(std::string entry);

          //Function to clear log
          void clear();

          //Getter to return reference to font
          sf::Font& getFont();

     private:
          //Text drawn to screen
          sf::Text title;
          sf::Text aText;
          std::deque<std::string> aEntries;
          sf::Font font;
          
          //Total number of entries allowed 
          //(may be altered depending on screen resolution)
          unsigned int max;

          //game object pointer used to draw to window
          Game* game;
};

#endif
