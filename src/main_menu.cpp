//cpp file for main menu
#include "main_menu.hpp"
#include "state_man.hpp"
#include "action.hpp"
#include "map.hpp"
#include "paths.hpp"

#include <SFML/Graphics.hpp>
     using namespace sf;
#include <iostream>

//Constructor
Main_Menu::Main_Menu(Game* game_,Map* map_) {
if(DEBUG) std::cout << "Main Menu Constructor called" << std::endl;

     //Load in menu font, throw an exception if font not found
     if(!font.loadFromFile(MENU_FONT)) {

          throw "Font not loaded";

     }

     //Set text
     title.setFont(font);
     title.setString("SOCIETY");
     title.setCharacterSize(TITLESIZE);

     publisher.setFont(font);
     publisher.setString("By: Team DZJK");
     publisher.setCharacterSize(PUBSIZE);
     
     button_1.setFont(font);
     button_1.setString("Play");
     button_1.setCharacterSize(TXTSIZE);
     
     button_2.setFont(font);
     button_2.setString("Tutorial");
     button_2.setCharacterSize(TXTSIZE);
     
     button_3.setFont(font);
     button_3.setString("Quit");
     button_3.setCharacterSize(TXTSIZE);
     //Set text position
     title.setPosition(Vector2f(TITLEPOS));
     publisher.setPosition(Vector2f(PUBPOS-20.f));
     button_1.setPosition(Vector2f(PLAYPOS-20.f));
     button_2.setPosition(Vector2f(TUTPOS-20.f));
     button_3.setPosition(Vector2f(EXITPOS-20.f));

     //Set button size
     play_rect = RectangleShape(Vector2f(HSIZE1, VSIZE));
     opt_rect = RectangleShape(Vector2f(HSIZE2, VSIZE));
     exit_rect = RectangleShape(Vector2f(HSIZE3, VSIZE));
     //Set button texture/color
     play_rect.setFillColor(Color(100, 250, 50));
     opt_rect.setFillColor(Color(100, 250, 50));
     exit_rect.setFillColor(Color(100, 250, 50));

     //Set button location
     play_rect.setPosition(Vector2f(PLAYPOS));
     opt_rect.setPosition(Vector2f(TUTPOS));
     exit_rect.setPosition(Vector2f(EXITPOS));

     selected = start;
     n = 0;
     map = map_;

     //Create a game object
     game = game_;
if(DEBUG) std::cout << "Main Menu constructor successfully finished" << std::endl;
}

void Main_Menu::draw() {

     game->window.clear();
     game->window.draw(play_rect);
     game->window.draw(opt_rect);
     game->window.draw(exit_rect);
     game->window.draw(title);
     game->window.draw(publisher);
     game->window.draw(button_1);
     game->window.draw(button_2);
     game->window.draw(button_3);
}

void Main_Menu::update() {
  switch(selected) {
                 case start:
                           play_rect.setFillColor(Color(250, 0, 50));
                           opt_rect.setFillColor(Color(100, 250, 50));
                           exit_rect.setFillColor(Color(100, 250, 50));
                           break;
                 case options:
                           play_rect.setFillColor(Color(100, 250, 50));
                           opt_rect.setFillColor(Color(250, 0, 50));
                           exit_rect.setFillColor(Color(100, 250, 50));
                           break;
                 case exit:
                           play_rect.setFillColor(Color(100, 250, 50));
                           opt_rect.setFillColor(Color(100, 250, 50));
                           exit_rect.setFillColor(Color(250, 0, 50));
                           break;
                 default: break;
            }
}

void Main_Menu::handleInput() {
                 //Only read input if input is a key press
                 if(game->event.type == Event::KeyPressed) {
                      //If "Enter" button is pressed, initiate action of selected button
                      if(game->event.key.code == Keyboard::Return) {
                           switch(selected) {
                                case start:
                                     //start the game
                                     std::cout << "Game started" << std::endl;
                                     game->pushState(new Action(game,map));
                                     break;
                                case options:
                                     //Do nothing for now
                                     std::cout <<"Option selected" <<std::endl;
                                     break;
                                case exit:
                                     //Exit the application
                                     std::cout << "Exiting" <<std::endl;
                                     game->window.close();
                                     return; break;
                                default: break;
                           }
                      }
                 //If "Down" arrow key pressed, scroll down menu
                 if(game->event.key.code == Keyboard::Down) {
                      if(selected < exit) {
                           n+=1;
                           selected = static_cast<select>(n); }
                 }
                 //If "Up" arrow key pressed, scroll up menu
                 if(game->event.key.code == Keyboard::Up) {
                      if(selected > start) {
                           n -=1;
                           selected = static_cast<select>(n); }
                 }
                 //If Close pressed, exit game
                 else if(game->event.type == Event::Closed) {
                      game->window.close();
                      }

                 }
}

