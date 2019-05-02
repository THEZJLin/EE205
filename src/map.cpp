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

//Sets population of a square with index "n"
void Map::setPop(int n_) {
     square[n_]->pop = 5;
}

//Population to grow population (should be called every turn)
void Map::updatePop() {
     //Variables to keep track of births/deaths for current square
     int tile_births;
     int tile_deaths;
     //Variables to keep track of total births/deaths for current turn
     int tot_births = 0;
     int tot_deaths = 0;

     int i = 0;

     //Used to keep track of current square
     for(vector<Square*>::iterator it = square.begin();it!=square.end();++it) {
          //Calculate births and add to square population
          tile_births = (int) (((*it)->pop) * ((*it)->birth));
          
          //Calculate deaths and subtract from square population
          tile_deaths = (int) (((*it)->pop) * ((*it)->death));
          (*it)->pop += tile_births - tile_deaths;
          //If population is above max, kill off excess population
          if((*it)->pop > MAX) {
               tile_deaths += ((*it)->pop - MAX);
               (*it)->pop = MAX;
          }

          //Increment total births/deaths for turn
          tot_births += tile_births;
          tot_deaths += tile_deaths;

          //Expand population to adjacent tiles if population threshold is met
          std::cout<<"debug1"<<std::endl;
          expandPop(it);
          std::cout<<"debug2"<<std::endl;


if(DEBUG) std::cout << "i = "<<i<<"pop="<<square[i]->pop<<std::endl;

          //(PLACEHOLDER) Change fill color if square is occupied
          if((*it)->pop != 0) {
               (*it)->rect.setFillColor(Color::Red);
          }

     }
}

//Takes in an iterator to the map vector. If a tile hits a certain population, part of the population will head out to adjacent tiles
void Map::expandPop(std::vector<Square*>::iterator tile) {
     //If population is greater than threshold, check if adjacent tiles are available
     if((*tile)->pop >= THRESHOLD) {
          
          //Check if tile is in bounds (tile above)
          if( (*tile)->n >= MAP_DIM ) {
               //Add settlers if population of adjacent tile is below max
               if(tile[-MAP_DIM]->pop < MAX) {
                    (*tile)->pop -= SETTLERS;
                    tile[-MAP_DIM]->pop += SETTLERS;
               }
          }

          //Check if tile is in bounds (tile below)
          if( (*tile)->n < ((MAP_DIM*MAP_DIM) - MAP_DIM) ) {
               //Add settlers if population of adjacent tile is below max
               if(tile[MAP_DIM]->pop < MAX) {
                    (*tile)->pop -= SETTLERS;
                    tile[MAP_DIM]->pop += SETTLERS;
               }
          }
          
          //Check if tile is in bounds (tile left)
          if( (*tile)->n % MAP_DIM ) {
               //Add settlers if population of adjacent tile is below max
               if(tile[LEFT]->pop < MAX) {
                    (*tile)->pop -= SETTLERS;
                    tile[LEFT]->pop += SETTLERS;
               }
          }

          //Check if tile is in bounds (tile right)
          if( (((*tile)->n)+1) % MAP_DIM ) {
               //Add settlers if population of adjacent tile is below max
               if(tile[RIGHT]->pop < MAX) {
                    (*tile)->pop -= SETTLERS;
                    tile[RIGHT]->pop += SETTLERS;
               }
          }
     }
}
