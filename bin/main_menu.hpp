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
#define HSIZE1 game_->desktop.width
#define HSIZE2 game_->desktop.width * .5555
#define HSIZE3 game_->desktop.width * .2777
#define VSIZE  game_->desktop.height * .0833
//Specifiers for text size
#define TITLESIZE game_->desktop.height * .225
#define PUBSIZE game_->desktop.height * .0688
#define TXTSIZE game_->desktop.height * .0822
//Specifiers for element positions
#define TITLEPOS 0.f,game_->desktop.height*.0625
#define PUBPOS 0.f,game_->desktop.height*.4311
#define PLAYPOS 0.f,game_->desktop.height*.5
#define TUTPOS 0.f,game_->desktop.height*.6666
#define EXITPOS 0.f,game_->desktop.height*.8333
//Specifiers for button text positions (offset by 20.f)
#define PUBPOST 0.f,(game_->desktop.height*.43111)-(game_->desktop.height*.011)
#define PLAYPOST 0.f,(game_->desktop.height*.5000)-(game_->desktop.height*.011)
#define TUTPOST 0.f,(game_->desktop.height*.66666)-(game_->desktop.height*.011)
#define EXITPOST 0.f,(game_->desktop.height*.8333)-(game_->desktop.height*.011)
//Value to control debug statements
#define DEBUG 1


//Main menu class
class Main_Menu : public GameState 
{
     public:
          //constructor
          Main_Menu(Game* game_, Map* map_);

          //Inherited virtual functions
          void draw();
          void update();
          void handleInput();

          //Map to pass to next state
          Map* map;

     private:
       //menu button shapes
       RectangleShape play_rect;
       RectangleShape opt_rect;
       RectangleShape exit_rect;
       RectangleShape background;

       Texture back;

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
