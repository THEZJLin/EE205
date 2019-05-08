#include "turn.hpp"
#include "paths.hpp"


//Constructor
Turn::Turn(Game* game_, Map* map_, Console* log_, Player* player_) :  
                                                    viewTileTxt("Explore",log_->getFont(),game_->desktop.height*.1),
                                                    buildTxt("Build",log_->getFont(),game_->desktop.height*.1),
                                                    skillTxt("Skills",log_->getFont(),game_->desktop.height*.1),
                                                    endTurnTxt("End Turn",log_->getFont(),game_->desktop.height*.1), 
                                                    soulsTxt("Souls: ",log_->getFont(),game_->desktop.height*.05), 
                                                    player(player_) {
     
     //Set inherited pointers
     game = game_;
     map = map_;
     log = log_;


     //Set button sizes
     float sizeX = game->desktop.width*.25;
     float sizeY = game->desktop.height*.2;

     viewTile.setSize(Vector2f(sizeX,sizeY));
     build.setSize(Vector2f(sizeX,sizeY));
     skill.setSize(Vector2f(sizeX,sizeY));
     endTurn.setSize(Vector2f(sizeX,sizeY));

     //set element coordinates
     float posY = game->desktop.height*.8;

     viewTile.setPosition(0,posY);
     viewTileTxt.setPosition(0,posY);

     build.setPosition(sizeX,posY);
     buildTxt.setPosition(sizeX,posY);

     skill.setPosition(2*sizeX,posY);
     skillTxt.setPosition(2*sizeX,posY);

     endTurn.setPosition(3*sizeX,posY);
     endTurnTxt.setPosition(3*sizeX,posY);

     soulsTxt.setPosition(game->desktop.height*PERCENT,posY*(.75/.8));

     //Add buttons to vector
     menButt.push_back(viewTile);
     menButt.push_back(build);
     menButt.push_back(skill);
     menButt.push_back(endTurn);

     //Set iterator to start on first option
     it = menButt.begin();
     n = 0;

     //Add text to vector
     menTxt.push_back(&soulsTxt);
     menTxt.push_back(&viewTileTxt);
     menTxt.push_back(&buildTxt);
     menTxt.push_back(&skillTxt);
     menTxt.push_back(&endTurnTxt);

     stringstream ss;
     ss << "Start Turn: " << player->getFaction();
     log->pushEntry(ss.str());
}



//Handle user input
void Turn::handleInput() {
     
     
     //Only read input if input is a key press
     if(game->event.type == Event::KeyPressed) {

          switch(game->event.key.code) {
               //Switch statements for when "return" button pressed
               // (game changes states)
               case(Keyboard::Return): 
                    if(n == 0) {log->pushEntry("View state pushed");}
                    if(n == 1) {log->pushEntry("Build state pushed");}
                    if(n == 2) {log->pushEntry("Skill state pushed");}
                    if(n == 3) {log->pushEntry("Turn end"); 
                                player->addSouls(map->updatePop(player->getFaction()));
                                game->popState();}

                    break;



               //Switch statements for scrolling through options
               case(Keyboard::Right):
                    if(it != menButt.end()-1) { it++; n++;}
                    else {it = menButt.begin(); n=0;}
                    break;

               case(Keyboard::Left):
                    if(it != menButt.begin()) { it--;n--;}
                    else { it = menButt.end()-1; n=menButt.size()-1;}
                    break;

               //If any other keys are pressed, do nothing
               default: break;
          }
     }

     //If close button pressed, close window
     if(game->event.type == Event::Closed) { game->window.close(); }


}



//Update button colors to reflect selected option
void Turn::update() {

     //Make all buttons one color
     for(auto& i : menButt) { i.setFillColor(Color(100,250,50)); }

     //Set selected button to a different color
     it->setFillColor(Color::Red);

     //Update total souls
     stringstream ss;
     ss << "Souls: "<< player->getSouls();
     soulsTxt.setString(ss.str());

}



//Draw all elements to screen
void Turn::draw() {
     
     game->window.clear();
     map->draw(game);
     log->draw();
     //Draw buttons
     for(auto i : menButt) { game->window.draw(i); }
     //Draw text
     for(auto i : menTxt) { game->window.draw(*i); }
     //game->window.draw(soulsTxt);

}
