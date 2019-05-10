#ifndef F_UTILITIES_HPP
#define F_UTILITIES_HPP

#include <string>

//Playable factions, each faction has different skills
enum faction { Greeks, Christians, None };

//Terrain types for tiles
enum tileType { plain, forest, desert, ocean, mountain };
tileType charToTileType(char in);

#endif
