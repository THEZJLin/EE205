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
//Class creates squares used in grid, it also stores game information (population, modifiers, etc)
class Square {
     public:
          //Parameters
          int population = 0;
          terrain tileType;
          float birth;
          float death;
          //Constructor
          Square(int x_pos, int y_pos, int n_);

          //Graphical appearance
          RectangleShape rect;

          //Setters
          //setPopulation(int p);

          void setTileType(terrain t);
          //Getters

     private:
          //Unique square identifier
          unsigned n;
          //Population parameter, vector stores population of all factions on square
          std::vector<unsigned> pop;

};

#endif
