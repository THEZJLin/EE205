//Main file for testing

#include "main_menu.hpp"
#include "action.hpp"
#include "map.hpp"


int main() {
     //Create the window
//     RenderWindow window(VideoMode(800, 600), "TEST");
//     Event event;

     //Initialize objects needed for game state (always starts at Main Menu)
     Map map;
     Game game;
     game.pushState(new Main_Menu(&game));

     //Run until window closes
     while(game.window.isOpen()) {
          //Read event
          while(game.window.pollEvent(game.event)) 
          {

               game.getState()->handleInput();

          }

          //Update graphics accordingly
          game.getState()->update();
          //Redraw screen
          game.getState()->draw();
          //Push buffer to screen
          game.window.display();
     }
}


