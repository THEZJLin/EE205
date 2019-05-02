#include "map.hpp"

//Constructor, creates new squares and pushes them into the map vector
Map::Map() {
     n = 0;
     for(int j=0; j<MAP_DIM; j++) {
          for(int i=0; i<MAP_DIM; i++) {
               //Coordinates of new square are modified by the "SIZE"
               //alias defined in square.cpp
               square.push_back(new Square(i*SIZE,j*SIZE,n));
               //Defualts all of the map tiles to have forest terrain
               (*(square.rbegin()))->setTileType(forest);
               //n is incremented to avoid 2 squares having the same
               //identifier
               n++;
          }
     }

}

//Destructor
Map::~Map() {
     std::vector<Square*>::iterator it = square.begin();
     std::vector<Square*>::iterator it2;
     while(it != square.end()) {
          it2 = it;
          it++;
          delete *it2;

     }
}

void Map::setSpawn(int s) {
     square[s]->population = 1;
}

