#ifndef SKILLCAST_HPP
#define SKILLCAST_HPP

#include "movement.hpp"
#include "skills.hpp"

class MoveSkill : public Movement {
     public:
          //Constructor, destructor
          MoveSkill(Map* map_,Game* game_, Skills* skill_,faction player_);
          void update();
          void draw();
          void handleInput();

     Skills* skill;
     faction player;
};

#endif
