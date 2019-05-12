#include "use_skill.hpp"
#include "paths.hpp"


//Constructor
useSkill::useSkill(Game* game_, Map* map_, Console* log_, Player* player_) :  
                                                    skill1("Skill 1",log_->getFont(),game_->desktop.height*.08),
                                                    skill2("Skill 2",log_->getFont(),game_->desktop.height*.08),
                                                    skill3("Skill 3",log_->getFont(),game_->desktop.height*.08),
                                                    cancel("Cancel",log_->getFont(),game_->desktop.height*.08), 
                                                    soulsTxt("Souls: ",log_->getFont(),game_->desktop.height*.04), 
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
     skill1.setPosition(0,posY);

     build.setPosition(sizeX,posY);
     skill2.setPosition(sizeX,posY);

     skill.setPosition(2*sizeX,posY);
     skill3.setPosition(2*sizeX,posY);

     endTurn.setPosition(3*sizeX,posY);
     cancel.setPosition(3*sizeX,posY);

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
     menTxt.push_back(&skill1);
     menTxt.push_back(&skill2);
     menTxt.push_back(&skill3);
     menTxt.push_back(&cancel);

     stringstream ss;
     ss << "Use skill";
     log->pushEntry(ss.str());
}



//Handle user input
void useSkill::handleInput() {
     
     
     //Only read input if input is a key press
     if(game->event.type == Event::KeyPressed) {

          switch(game->event.key.code) {
               //Switch statements for when "return" button pressed
               // (game changes states)
               case(Keyboard::Return): 
               
                    if(n == 0) {
                         log->clear();
                         log->pushEntry("GROWTH");
                         log->pushEntry("Use on an empty tile to plant a population seed");
                         if(player->getSouls() > MAX*2) { 
                              player->addSouls(-MAX*2);
                              skills = new growth();
                              game->pushState(new MoveSkill(map,game,skills,player->getFaction(),log));
                         }
                         else { log->pushEntry("NOT ENOUGH SOULS, need 1200"); }
                    }
                    if(n == 1) {
                         log->clear();
                         log->pushEntry("EARTHQUAKE");
                         log->pushEntry("Converts all people in a row to your religion");
                         if(player->getSouls() > MAX*50) { 
                              player->addSouls(-MAX*50);

                              skills = new earthquake();
                              game->pushState(new MoveSkill(map,game,skills,player->getFaction(),log));
                         }
                         else { log->pushEntry("NOT ENOUGH SOULS, need 30000"); }
                    }
                    if(n == 2) {
                         log->clear();
                         log->pushEntry("FIST");
                         log->pushEntry("Smash a square into oblivion");
                         if(player->getSouls() > MAX) { 
                              player->addSouls(-MAX);
                              skills = new fist();
                              game->pushState(new MoveSkill(map,game,skills,player->getFaction(),log));
                         }
                         else { log->pushEntry("NOT ENOUGH SOULS, need 600"); }
                    }

                    if(n == 3) { game->popState(); }

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
void useSkill::update() {

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
void useSkill::draw() {
     
     game->window.clear();
     map->draw(game);
     log->draw();
     //Draw buttons
     for(auto i : menButt) { game->window.draw(i); }
     //Draw text
     for(auto i : menTxt) { game->window.draw(*i); }
     //game->window.draw(soulsTxt);

}

useSkill::~useSkill() {
     delete skills;
}
