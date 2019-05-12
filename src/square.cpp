#include "square.hpp"
#include "texture_man.hpp"

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
     pop = 0;

     //Set ownership value
     ownedBy = None;
}
//Sets Population value in a square

//Terrain modifiers
void Square::setTileType(tileType t, TexManager& texManager) {
     switch(t) {
          case plain: 
               birth = .8;
               death = .2;
               terrain = plain;
               rect.setTexture(&(texManager.getTex("plain")));
               break;

          case forest : 
               birth = .9;
               death = .2;
               terrain = forest;
               rect.setTexture(&(texManager.getTex("forest")));
               break;

          case desert :
               birth = .5;
               death = .9;
               terrain = desert;
               rect.setTexture(&(texManager.getTex("desert")));
               break;

          case ocean :
               birth = 0;
               death = .5;
               terrain = ocean;
               rect.setTexture(&(texManager.getTex("ocean")));
               break;
               
          case mountain :
               birth = 0;
               death = 1;
               terrain = mountain;
               rect.setTexture(&(texManager.getTex("mountain")));
               break;
          }
     }

void Square::setBuilding(building b) {
     if (b == temple) {
          buildingType = temple;
          //bool loadFromFile(const std::string &./resources/GodTemple.png);
     }


}
