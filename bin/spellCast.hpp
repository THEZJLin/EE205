#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP
#include<SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include "game.hpp"
#include "state_man.hpp"
#include "skill.hpp"
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
	int i;
	//This is the current cursors image
     sf::Sprite* cursorimage;
     
     //skill being used
     Skill* skill;
	float xindex, yindex, percent, size;
	int move;
	};
#endif 
