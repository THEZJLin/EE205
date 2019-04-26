#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "square.hpp"
#include <vector>

//Grid parameters
#define MAP_DIM 20

//The "map" used in the game, consists of a grid of "Square" objects
class Map {
     public:
          //Constructor and destructor
          Map();
          ~Map();

          //squares making up the map are stored here
          std::vector<Square*> square;

     private:

          //current number of squares in grid
          unsigned n;
};

#endif

