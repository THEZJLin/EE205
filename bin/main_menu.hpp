#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "game.hpp"
#include "state_man.hpp"
#include <SFML/Graphics.hpp>
     using namespace sf;
#include <iostream>

//Specifiers to alter button appearance
#define TITLE "PLACEHOLDER"
#define HSIZE 1200.f
#define VSIZE 250.f
#define PLAYPOS 250,900
#define OPTPOS 250.f,1200.f
#define EXITPOS 250.f,1500.f

//Value to control debug statements
#define DEBUG 1


//Main menu class
class Main_Menu : public GameState 
{
     public:
          //constructor
          Main_Menu();

          //Inherited virtual functions
          void draw();
          void update();
          void handleInput();

     private:
       //menu button shapes
       RectangleShape play_rect;
       RectangleShape opt_rect;
       RectangleShape exit_rect;

       //Title text
       Text title;

       //Button text
      // Text play;
      // Text option;
      // Text exit;

       //Enumerator to keep track of button position
       enum select { start, options, exit };
       select selected;
       int n;
};


#endif
