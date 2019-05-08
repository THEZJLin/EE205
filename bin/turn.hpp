#ifndef TURN_HPP
#define TURN_HPP

#include "state_man.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
     using namespace sf;
#include <vector>


//This is the "turn" state class. It provides an option menu
//on player's turn (Place building, use skill, etc)

class Turn : public GameState {
     public:
          //Constructor
          Turn(Game* game_, Map* map_, Console* log_, Player* player);

          //Inherited virtual functions
          void draw();
          void update();
          void handleInput();

          //Player whose turn it is
          Player* player;


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
          Text viewTileTxt;
          Text buildTxt;
          Text skillTxt;
          Text endTurnTxt;

          //Player information text
          Text soulsTxt;

          Font font;


};

#endif
