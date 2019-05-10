//Main file for testing
#include "main_menu.hpp"
#include "action.hpp"
#include "map.hpp"
#include "paths.hpp"
#include <string>


int main() {
     //Initialize objects needed for game state (always starts at Main Menu)
     Game game;

//* Feel like hardcoding, IDK may delete later

game.texManager.loadTex("plain",PLAIN);
game.texManager.loadTex("forest",FOREST);
game.texManager.loadTex("mountain",MOUNTAIN);
game.texManager.loadTex("ocean",OCEAN);
game.texManager.loadTex("desert",DESERT);

//*

     Map map(&game);
     game.pushState(new Main_Menu(&game, &map));


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
     std::cout << "ending program" << std::endl;
}


