#include "moveSkills.hpp"


MoveSkill::MoveSkill(Map* map_, Game* game_, Skills* skill_) : Movement(map_,game_) , skill(skill_) {}

void MoveSkill::update() {
     if(it != nullptr) {
          skill->use_skill(it);


