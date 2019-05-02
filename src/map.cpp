#include "map.hpp"

//Constructor, creates new squares and pushes them into the map vector
Map::Map() {
     n = 0;
     for(int i=0; i<MAP_DIM;++i) {
          for(int j=0; j<MAP_DIM; ++j) {
               //Coordinates of new square are modified by the "SIZE"
               //alias defined in square.cpp
               square.push_back(new Square(i*SIZE,j*SIZE,n));
               
               //n is incremented to avoid 2 squares having the same
               //identifier
               n++;
          }
     }

}

//Destructor
Map::~Map() {
     std::vector<Square*>::reverse_iterator it2;
     for(std::vector<Square*>::reverse_iterator it=square.rbegin();it!=square.rend();++it) {
          delete *it2;
          it2 = it;
     }
}

void Map::setSpawn(int s) {
     square[s]->population = 1;
}

