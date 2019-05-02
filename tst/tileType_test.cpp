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


          map.setSpawn(10);
          map.square[10]->setTileType(plain);
          std::cout << "Square 10 is now forest type" << std::endl;


          //Update graphics accordingly
          game.getState()->update();
          //Redraw screen
          game.getState()->draw();
          //Push buffer to screen
          game.window.display();

     }
}

//make command probably
//g++ -c ./tst/tileType_test.cpp -I./bin/ -o ./tst/tileType_test.o


//g++ ./tst/tileType_test.o ./src/main_menu.o ./src/game.o ./src/square.o ./src/map.o ./src/action.o  -o ./tst/a.out -lsfml-graphics -lsfml-window -lsfml-system