#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>
     using namespace sf;
#include <vector>
#include <iostream>

//Parameter aliases
#define SIZE 100
#define SPAWN1 20
//Alias for tyleType
enum terrain {plain, forest, desert, ocean, mountain};
enum building {temple};
//Class creates squares used in grid, it also stores game information (population, modifiers, etc)
class Square {
     public:
          //Parameters

          //Terrain of square
          terrain tileType;
          building buildingType;
          //Population growth rates
          float birth;
          float death;

          //Constructor
          Square(int x_pos, int y_pos, int n_);

          //Graphical appearance
          RectangleShape rect;

          //Setters
          //setPopulation(int p);

          //Sets the terrain type of the square
          void setTileType(terrain t);

          //Sets a texture of a building

          //Sets a building in a square
          void setBuilding(building b);
          //Getters

          //Unique square identifier
          unsigned n;
          //Population parameter, vector stores population of all factions on square
          int pop;

     private:

};

#endif
