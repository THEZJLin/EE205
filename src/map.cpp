#include "map.hpp"
#include <fstream> //std::ifstream
#include <string> //std::string, std::stoi

//Constructor, creates new squares and pushes them into the map vector
Map::Map(Game* game) {
     n = 0;

     //Variables for loading in map from file
     char c[2];
     std::ifstream mapFile(PLAINS);

     //Calculate square size based on current screen resolution
     float size;
     size = ( ((game->desktop.height)*PERCENT) / MAP_DIM );

     //Create squares and push them into vector
     for(int j=0; j<MAP_DIM; j++) {
          for(int i=0; i<MAP_DIM; i++) {
               //Coordinates of new square are modified by the "SIZE"
               //alias defined in square.cpp
               square.push_back(new Square(i*size,j*size,size,n));

               //Read in tile type from file
               c[0] = mapFile.get();

               //get next character if newline
               if(c[0] == '\n') { c[0] = mapFile.get(); }

               //Convert string into enumerator and set tile type
               (*(square.rbegin()))->setTileType(charToTileType(c[0]),game->texManager);

               //n is incremented to avoid 2 squares having the same
               //identifier
               n++;
          }
     }
     //Close file
     mapFile.close();
}




//Destructor
Map::~Map() {
     int i = 0;
     std::cout << "calling map deconstructor" << std::endl;
     std::vector<Square*>::iterator it = square.begin();
     std::vector<Square*>::iterator it2;
     while(it != square.end()) {
     std::cout << "deleting: " << i << std::endl;
          it2 = it;
          it++;
          delete *it2;
          std::cout << "deleted: " << i << std::endl;
     i++;

     }
     std::cout << "map deconstructor complete!" <<std::endl;
}


//Function to draw map to screen
void Map::draw(Game* game_) {
     for(auto it : square) {
             game_->window.draw(it->rect);
     }
}




//Sets population and ownership of a square with index "n"
void Map::setPop(int n_, faction ownedBy_) {
     square[n_]->pop = 100;
     square[n_]->ownedBy = ownedBy_;
}



//Population to grow population (should be called every turn), returns deaths
float Map::updatePop(faction fact) {
     //Variables to keep track of births/deaths for current square
     int tile_births;
     int tile_deaths;
     //Variables to keep track of total births/deaths for current turn
     int tot_births = 0;
     int tot_deaths = 0;

     int i = 0;

     //Used to keep track of current square
     for(vector<Square*>::iterator it = square.begin(); it!= square.end() ; ++it) {
		 if(fact == (*it)->ownedBy) {
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


     }
	
     
     for(vector<Square*>::iterator it = square.begin(); it!= square.end() ; ++it) {
           //Expand population to adjacent tiles if population threshold is met
		 expandPop(it);
     
     }


     //(PLACEHOLDER) Change fill color if square is occupied
     if((*it)->ownedBy == Christians) {
           (*it)->rect.setFillColor(Color::Red);
      }

      else if((*it)->ownedBy == Greeks) {(*it)->rect.setFillColor(Color::Blue);}

     }


     return tot_deaths;
}

void Map::Attack(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender)
{


	if((*attacker)->pop > (*defender)->pop)
	{
		(*defender)->pop = 0;
		(*defender)->ownedBy = (*attacker)->ownedBy;
	}
	else
	{
		(*attacker)->pop = 0;
		(*attacker)->ownedBy = (*defender)->ownedBy;
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
								 if((*tile)->ownedBy != tile[-MAP_DIM]->ownedBy && tile[-MAP_DIM]->ownedBy != None)
								 	{Attack(tile, (tile-MAP_DIM));}
                    (*tile)->pop -= SETTLERS;
                    tile[-MAP_DIM]->pop += SETTLERS;
                    //Set tile ownership
                    tile[-MAP_DIM]->ownedBy = (*tile)->ownedBy;

               }
          }

          //Check if tile is in bounds (tile below)
          if( (*tile)->n < ((MAP_DIM*MAP_DIM) - MAP_DIM) ) {
               //Add settlers if population of adjacent tile is below max
               if(tile[MAP_DIM]->pop < MAX) {
								 if((*tile)->ownedBy != tile[MAP_DIM]->ownedBy && tile[MAP_DIM]->ownedBy!=None)
								 	{Attack(tile, (tile+MAP_DIM));}
                    (*tile)->pop -= SETTLERS;
                    tile[MAP_DIM]->pop += SETTLERS;
                    //Set tile ownership
                    tile[MAP_DIM]->ownedBy = (*tile)->ownedBy;
               }
          }

          //Check if tile is in bounds (tile left)
          if( (*tile)->n % MAP_DIM ) {
               //Add settlers if population of adjacent tile is below max
               if(tile[LEFT]->pop < MAX) {
								 if((*tile)->ownedBy != tile[LEFT]->ownedBy && tile[LEFT]->ownedBy != None)
								 	{Attack(tile, (tile+LEFT));}
                    (*tile)->pop -= SETTLERS;
                    tile[LEFT]->pop += SETTLERS;
                    //Set tile ownership
                    tile[LEFT]->ownedBy = (*tile)->ownedBy;
               }
          }

          //Check if tile is in bounds (tile right)
          if( (((*tile)->n)+1) % MAP_DIM ) {
               //Add settlers if population of adjacent tile is below max
               if(tile[RIGHT]->pop < MAX) {
								 if((*tile)->ownedBy != tile[RIGHT]->ownedBy && tile[RIGHT]->ownedBy!=None)
								 	{Attack(tile, (tile+RIGHT));}
                    (*tile)->pop -= SETTLERS;
                    tile[RIGHT]->pop += SETTLERS;
                    //Set tile ownership
                    tile[RIGHT]->ownedBy = (*tile)->ownedBy;
               }
          }
     }
}
