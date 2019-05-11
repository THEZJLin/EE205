#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include<SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include "game.hpp"
#include "state_man.hpp"
//value to control debug statements
#define DEBUG 1

class SkillCast : public GameState{
	private:

	public:
	//constructor
	SkillCast(Map* map_, Game* game_,Sprite* cursor, Skill* skill_);
	Map* map;
	Game* game;
	void draw();
	void update();
	void handleInput();

     //Variables to keep track of current square
	int i;
     vector<Square*>::iterator it;

	//This is the current cursors image
     sf::Sprite* cursorimage;
	float xindex, yindex, percent, size;
	int move;
};

#endif 
