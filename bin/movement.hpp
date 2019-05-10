#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include<SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include "game.hpp"
#include "state_man.hpp"
//value to control debug statements
#define DEBUG 1

class Movement:public GameState{
	private:

	public:
	//constructor
	Movement(Map* map_, Game* game_);
	Map* map;
	Game* game;
	void draw();
	void update();
	void handleInput();
	int i;
	//This is the current cursors image
     sf::Texture tex;
     sf::Sprite cursorimage;
	float xindex, yindex, percent, size;
	int move;
	};
#endif 
