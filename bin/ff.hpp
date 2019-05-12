#ifndef FF_HPP
#define FF_HPP

#include "state_man.hpp"
#include "map.hpp"
#include "console.hpp"

//State to fast forward
class FF : public GameState {
     public:

     FF(Map* map_, Game* game_,Console* log_);
     void update();
     void draw();
     void handleInput();

     Console* log;
};


#endif
