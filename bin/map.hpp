#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
     using namespace sf;
#include "game.hpp"
#include "square.hpp"
#include "paths.hpp"
#include "utilities.hpp"
#include <vector>

//Grid parameters
#define MAP_DIM 15
#define SPAWN1 20
//Threshold before population expands to adjacent tiles
#define THRESHOLD 15
#define MAX 200
//Number of people that move to adjacent tiles upon reaching thresh
#define SETTLERS 5
#define LEFT -1
#define RIGHT 1
//Percentage of screen taken up by map (height)
#define PERCENT 0.8

class Game;

//The "map" used in the game, consists of a grid of "Square" objects
class Map {
     public:

          //Constructor and destructor
          Map(Game* game_);
          ~Map();

          //Setter functions
          void setPop(int n_, faction ownedBy_);

          //functions for expanding population
          float updatePop(faction fact);
					void Attack(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender);
          void expandPop(vector<Square*>::iterator tile);

          //squares making up the map are stored here
          std::vector<Square*> square;

          //function to draw map to screen
          void draw(Game* game_);

     private:

          //current number of squares in grid
          unsigned n;
};

#endif
