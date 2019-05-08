#include "square.hpp"

//Constructor, sets coordinates with given input arguments
Square::Square(int x_pos, int y_pos, int size_, int n_) {

     //Set graphical appearance of square
     rect = RectangleShape(Vector2f(size_, size_));

//==Place holder color until texture is implemented==
     rect.setOutlineThickness(1);
     rect.setOutlineColor(Color::Red);
//===================================================

     //Set coordinates of square
     rect.setPosition(Vector2f(x_pos, y_pos));

     //Set coordinates of first player's citizens
     //Assign values to square parameters
     n = n_;
     birth = .9;
     death = .9;
     pop = 0;

     //Set ownership value
     ownedBy = None;
}
//Sets Population value in a square

//Terrain modifiers
void Square::setTileType(terrain t) {
//std::cout << "Terrain is being set" << std::endl;
     switch(t) {
          case plain: 
               birth = birth * 1;
               death = death * 1;
               tileType = plain;
               std::cout << tileType << std::endl;
               rect.setFillColor(Color::Green);
               break;

          case forest : 
               birth = birth * 1.2;
               death = death * .8;
               tileType = forest;
               std::cout << tileType << std::endl;
               rect.setFillColor(Color::Yellow);
               break;

          case desert :
               birth = birth * .8;
               death = death * 1.2;
               tileType = desert;
               std::cout << tileType << std::endl;
               break;

          case ocean :
               birth = 0;
               death = death * .2;
               tileType = ocean;
               std::cout << tileType << std::endl;
               break;
               
          case mountain :
               birth = 0;
               death = 0;
               tileType = mountain;
               std::cout << tileType << std::endl;
               break;
          }
     }

void Square::setBuilding(building b) {
     if (b == temple) {
          buildingType = temple;
          //bool loadFromFile(const std::string &./resources/GodTemple.png);
     }


}
