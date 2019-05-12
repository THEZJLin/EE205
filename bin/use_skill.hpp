#ifndef USE_SKILL_HPP
#define USE_SKILL_HPP

#include "state_man.hpp"
#include "player.hpp"
#include "skills.hpp"
#include "map.hpp"
#include "skillCast.hpp" //state to cast a skill
#include <SFML/Graphics.hpp>
     using namespace sf;
#include <vector>


//This is the "turn" state class. It provides an option menu
//on player's turn (Place building, use skill, etc)

class useSkill : public GameState {
     public:
          //Constructor
          useSkill(Game* game_, Map* map_, Console* log_, Player* player_);

          //Destructor
          ~useSkill();

          //Inherited virtual functions
          void draw();
          void update();
          void handleInput();

          //Player whose turn it is
          Player* player;

          Skills* skills;


     private: 
          //Vector storing menu buttons
          vector<RectangleShape> menButt;
          vector<RectangleShape>::iterator it;
          int n;

          //Vector for menu text
          vector<Text*> menTxt;

          //Menu buttons
          RectangleShape viewTile;
          RectangleShape build;
          RectangleShape skill;
          RectangleShape endTurn;

          //Text on buttons
          Text skill1;
          Text skill2;
          Text skill3;
          Text cancel;

          //Player information text
          Text soulsTxt;

          Font font;


};

#endif
