#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>
     using namespace sf;
#include <vector>
#include <iostream>

#include "utilities.hpp"

//Parameter aliases
#define SPAWN1 20

enum building { temple };
//Class creates squares used in grid, it also stores game information (population, modifiers, etc)
class Square {
     public:
          //Constructor
          Square(int x_pos, int y_pos, int size_, int n_);

          //Enumerators setting tile parameters
          tileType terrain;
          building buildingType;
          faction ownedBy;

          //Population growth rates
          float birth;
          float death;
          
          //Graphical appearance
          RectangleShape rect;

          //Sets the terrain type of the square
          void setTileType(tileType t);

          //Sets a building in a square
          void setBuilding(building b);

          
          //Unique square identifier
          unsigned n;

          int pop;

     private:

};

#endif
