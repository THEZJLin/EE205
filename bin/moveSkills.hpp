#ifndef MOVESKILLS_HPP
#define MOVESKILLS_HPP

#include "movement.hpp"
#include "skills.hpp"

class MoveSkill : public Movement {
     public:
          //Constructor, destructor
          MoveSkill(Map* map_,Game* game_, Skills* skill_);
          void update();

     Skills* skill;
}

#endif
