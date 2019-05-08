#include "player.hpp"


//Constructor, player starts at 0 currency, has 1 tile owned (spawn)
Player::Player(faction fact_) : fact(fact_), 
                   souls(0),
                   tilesOwned(1) {}


//Setter for currency
void Player::setSouls(float souls_) { souls = souls_; }

//Add or subtract a value from current souls
void Player::addSouls(float soulsToAdd) { souls += soulsToAdd; }

//Setter for tiles owned by player
void Player::setTiles(float tiles) { tilesOwned = tiles; }



//Getter for currency
float Player::getSouls() { return souls; }

//Getter for tiles owned
float Player::getTiles() { return tilesOwned; }

//Getter for faction of player
faction Player::getFaction() { return fact; }


