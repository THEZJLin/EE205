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
void Square::setTileType(tileType t) {
     switch(t) {
          case plain: 
               birth = birth * 1;
               death = death * 1;
               terrain = plain;
               break;

          case forest : 
               birth = birth * 1.2;
               death = death * .8;
               terrain = forest;
               break;

          case desert :
               birth = birth * .8;
               death = death * 1.2;
               terrain = desert;
               break;

          case ocean :
               birth = 0;
               death = death * .2;
               terrain = ocean;
               break;
               
          case mountain :
               birth = 0;
               death = 0;
               terrain = mountain;
               break;
          }
     }

void Square::setBuilding(building b) {
     if (b == temple) {
          buildingType = temple;
          //bool loadFromFile(const std::string &./resources/GodTemple.png);
     }


}
