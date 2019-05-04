#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "square.hpp"
#include <vector>

//Grid parameters
#define MAP_DIM 7
#define SPAWN1 20
//Threshold before population expands to adjacent tiles
#define THRESHOLD 70
#define MAX 100
//Number of people that move to adjacent tiles upon reaching thresh
#define SETTLERS 5
#define LEFT -1
#define RIGHT 1

//The "map" used in the game, consists of a grid of "Square" objects
class Map {
     public:
          //Constructor and destructor
          Map();
          ~Map();
          void setPop(int n_);
          //squares making up the map are stored here
          std::vector<Square*> square;

          //functions for expanding population
          void updatePop();
          void expandPop(std::vector<Square*>::iterator tile);

          int total_deaths;

     private:

          //current number of squares in grid
          unsigned n;
};

#endif

