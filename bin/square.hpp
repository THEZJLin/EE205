#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>
     using namespace sf;
#include <vector>
#include <iostream>

//Parameter aliases
#define SIZE 100

//Class creates squares used in grid, it also stores game information (population, modifiers, etc)
class Square {
     public:
          //Constructor
          Square(int x_pos, int y_pos, int n_);

          //Graphical appearance
          RectangleShape rect;

          //Setters

          //Getters

     private:
          //Unique square identifier
          unsigned n;

          //Population parameter, vector stores population of all factions on square
          std::vector<unsigned> pop;

          //Terrain modifiers
          float birth;
          float death;
};

#endif
