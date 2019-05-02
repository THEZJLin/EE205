#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include "game.hpp"
#include "state_man.hpp"
#include <SFML/Graphics.hpp>
     using namespace sf;
#include <iostream>

//Specifiers to alter button appearance
#define TITLE "SOCIETY"
//Size for buttons 1-3
#define HSIZE1 1800.f
#define HSIZE2 1000.f
#define HSIZE3 500.f
#define VSIZE 150.f
//Specifiers for text size
#define TITLESIZE 425
#define PUBSIZE 124
#define TXTSIZE 148
//Specifiers for element positions
#define TITLEPOS 0.f,150.f
#define PUBPOS 0.f,776.f
#define PLAYPOS 0.f,900.f
#define TUTPOS 0.f,1200.f
#define EXITPOS 0.f,1500.f

//Value to control debug statements
#define DEBUG 1


//Main menu class
class Main_Menu : public GameState 
{
     public:
          //constructor
          Main_Menu(Game* game_);

          //Inherited virtual functions
          void draw();
          void update();
          void handleInput();

     private:
       //menu button shapes
       RectangleShape play_rect;
       RectangleShape opt_rect;
       RectangleShape exit_rect;

       //Menu font
       Font font;

       //Setters
       //void set_Text(int size_, int pos_)

       // text
       Text title;
       Text publisher;
       Text button_1;
       Text button_2;
       Text button_3;

       //Enumerator to keep track of button position
       enum select { start, options, exit };
       select selected;
       int n;
};


#endif
