//The "Game" class manages the current game "state" with a stack
//It also contains the SFML window usedi in the game

#include "game.hpp"
#include <iostream>

#define DEBUG 1

//constructor, takes in a game title string
Game::Game() {
if(DEBUG) std::cout << "Initializing game object" << std::endl;
     //Get resolution of machine
     desktop = VideoMode::getDesktopMode();

     //create game window
     window.create(desktop, "Society");

     //Game always starts at start menu
     current = Start;
if(DEBUG) std::cout << "Initialized game object" << std::endl;
}

//Pushes new state onto stack and changes game state
void Game::pushState(GameState* state) {
     states.push(state);
}

//Removes current state, and thus, goes back to last state
void Game::popState() {
     GameState* temp;
     temp = states.top();
     std::cout << "popping state from stack" << std::endl;
     states.pop();
     delete temp;
     std::cout << "popped state from stack" << std::endl;
}

//Returns enumerator with current state
state Game::viewState() {
     //Placeholder for now
     return Start;
}

GameState* Game::getState() {
     return states.top();
}

//Destructor
Game::~Game() {
     cout << "calling destructor" << endl;
     while(!states.empty()) {
          popState();
     }
     cout << "destructor finished" << endl;
}
     
