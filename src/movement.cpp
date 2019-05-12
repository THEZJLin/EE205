#include "movement.hpp"
#include "game.hpp"
#include "map.hpp"
#include <iostream>
#include <sstream>
#include<SFML/Graphics.hpp>
using namespace sf;

Movement::Movement(Map* map_,Game* game_,Console* log_){
     log = log_;
	map = map_;
	game = game_;
	i = 0;
	size = (((game->desktop.height)*0.8) / MAP_DIM );
	xindex = size/2;
	yindex = size/2;
	move = 5;
	//set element coordinates
	tex.loadFromFile("./resources/Movement/cursor.png");
     cursorimage.setTexture(tex);
	cursorimage.setPosition(xindex,yindex);
	cursorimage.setColor(sf::Color(255, 255, 255, 255));
	cursorimage.setScale(.25,.25);

}	

void Movement::draw(){
		game->window.clear();
          map->draw(game);
          log->draw();
          game->window.draw(cursorimage);
}
void Movement::update(){
	//initializes key presses
	//vector of square pointers
     stringstream ss;
	switch(move){
	case 0: //move up
				//moves cursor up one
				yindex = yindex-size;
				cursorimage.setPosition(xindex,yindex);
     ss << "Population of square "<<i<<": "<<map->square[i]->pop;
     log->pushEntry(ss.str());
			break;
	case 1: //move down, +n
				//moves cursor down one
				yindex = yindex+size;
				cursorimage.setPosition(xindex,yindex);
     ss << "Population of square "<<i<<": "<<map->square[i]->pop;
     log->pushEntry(ss.str());
			break;
	case 2: //move left, -1
				//moves cursor left one
				xindex = xindex - size;
				cursorimage.setPosition(xindex,yindex);
     ss << "Population of square "<<i<<": "<<map->square[i]->pop;
     log->pushEntry(ss.str());
			break;
	case 3: //move right, +1
				//moves cursor right one
				xindex = xindex + size;
				cursorimage.setPosition(xindex,yindex);
     ss << "Population of square "<<i<<": "<<map->square[i]->pop;
     log->pushEntry(ss.str());
			break;

		default: break;
	}
		//closes on window x
		if(game->event.type == Event::Closed) {
			game->window.close();
		}

     move = 4;

}
void Movement::handleInput(){
	//initializes key presses
	sf::Keyboard::Key x;
	if(game->event.type == Event::KeyPressed){
	     x = game->event.key.code;
	}
	else{}
	//vector of square pointers
	switch(x){
	case sf::Keyboard::Up: //move up
		//can't go up if you're already on the first row
		if(i <= MAP_DIM-1){
			move = 4;
		}
			else{
				//updates index
				i = i - MAP_DIM;
				move = 0;
			}
			break;
	case sf::Keyboard::Down: //move down, +n
		//can't go down if you're already on the bottom row
		if(i >=((MAP_DIM * MAP_DIM) - MAP_DIM)){}
			else{
				//updates index
				i = i + MAP_DIM;
				move = 1;
			}	
			break;
	case sf::Keyboard::Left: //move left, -1
		//if you're currently at a multiple of MAP_DIM you can't move left because that means you're already in the left column
		if((i)%MAP_DIM == 0){
			move = 4;
		}
			else{
				//updates index
				i--;
				move = 2;
			}
			break;
	case sf::Keyboard::Right: //move right, +1
		//if you're current location + 1 is a multiple of MAP_DIM you can't move right because that means you're already in the right column
		if((i+1)%MAP_DIM == 0){
			move = 4;
		}
			else{
				//updates index
				i++;
				move = 3;
			}
			break;
     case sf::Keyboard::Return:
          game->popState();
          break;
		default:break;
	}
		//closes on window x
		if(game->event.type == Event::Closed) {
			game->window.close();
			}
		else{}
	
}

