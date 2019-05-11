#include "map_select.hpp"

MapSelect::MapSelect(Map* map_) : map(map_) {}



void loadMap(const std::string& mapName,const std::string& path) {
     maps.insert( {mapName, path} )
