#include "utilities.hpp"

//Converts a input character into an enumerator
tileType charToTileType(char in) {
     
     switch(in) {
          case '0': return plain;
          case '1': return forest;
          case '2': return desert;
          case '3': return ocean;
          case '4': return mountain;
          //Return plain if invalid character is given
          default: return plain;
     }

}
