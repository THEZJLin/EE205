//cpp file for main menu
#include "main_menu.hpp"
#include "state_man.hpp"
#include "action.hpp"
#include "map.hpp"

#include <SFML/Graphics.hpp>
     using namespace sf;
#include <iostream>

//Constructor
Main_Menu::Main_Menu(Game* game_) {
if(DEBUG) std::cout << "Main Menu Constructor called" << std::endl;
     //Set button size
     play_rect = RectangleShape(Vector2f(HSIZE, VSIZE));
     opt_rect = RectangleShape(Vector2f(HSIZE, VSIZE));
     exit_rect = RectangleShape(Vector2f(HSIZE, VSIZE));
     //Set button texture/color
     play_rect.setFillColor(Color(100, 250, 50));
     opt_rect.setFillColor(Color(100, 250, 50));
     exit_rect.setFillColor(Color(100, 250, 50));

     //Set button location
     play_rect.setPosition(Vector2f(PLAYPOS));
     opt_rect.setPosition(Vector2f(OPTPOS));
     exit_rect.setPosition(Vector2f(EXITPOS));

     ////Set Title text
     //title.setFont();
     //title.setString(TITLE);
     //title.setCharacterSize(450);
     //title.setFillColor(Color::Green);
     //title.setStyle(Text::Bold | Text::Underlined);
     //Set other variables
     selected = start;
     n = 0;

     //Create a game object
     game = game_;
if(DEBUG) std::cout << "Main Menu constructor successfully finished" << std::endl;
}

void Main_Menu::draw() {

     game->window.clear();
     game->window.draw(play_rect);
     game->window.draw(opt_rect);
     game->window.draw(exit_rect);
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
                                     game->pushState(new Action(game,new Map()));
                                     break;
                                case options:
                                     //Do nothing for now
                                     std::cout <<"Option selected" <<std::endl;
                                     break;
                                case exit:
                                     //Exit the application
                                     std::cout << "Exiting" <<std::endl;
                                     game->window.close();
                                     break;
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

