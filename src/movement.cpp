#include "movement.hpp"
#include "game.hpp"
#include "map.hpp"
#include <iostream>
#include<SFML/Graphics.hpp>
using namespace sf;

Movement::Movement(Map* map_,Game* game_){
	map = map_;
	game = game_;
	i=0;
  //(PLACEHOLDER) spawnpoint for testing
  map->setPop(0,Christians);
}	

void Movement::draw(){
		game->window.clear();
		for(std::vector<Square*>::iterator it=map->square.begin();it!=map->square.end();++it) {
		game->window.draw((*it)->rect);
		}
}
void Movement::update(){
     std::cout<<"updating screen"<<std::endl;
     map->updatePop(Christians);
     map->updatePop(Greeks);

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
		if(i <= MAP_DIM-1){}
			else{
				//changes modified square back to uniform
				map->square[i]->rect.setOutlineThickness(1);
				map->square[i]->rect.setOutlineColor(Color::Red);
				i = i - MAP_DIM;
				//changes the new square at index to differentiate where you're located
				map->square[i]->rect.setOutlineThickness(2);
				map->square[i]->rect.setOutlineColor(Color::Black);
			}
			break;
	case sf::Keyboard::Down: //move down, +n
		//can't go down if you're already on the bottom row
		if(i >=((MAP_DIM * MAP_DIM) - MAP_DIM)){}
			else{
				//changes modified square back to uniform
				map->square[i]->rect.setOutlineThickness(1);
				map->square[i]->rect.setOutlineColor(Color::Red);
				i = i + MAP_DIM;
				//changes the new square at index to differentiate where you're located
				map->square[i]->rect.setOutlineThickness(2);
				map->square[i]->rect.setOutlineColor(Color::Black);
			}	
			break;
	case sf::Keyboard::Left: //move left, -1
		//if you're currently at a multiple of MAP_DIM you can't move left because that means you're already in the left column
		if((i)%MAP_DIM == 0){}
			else{
				//changes modified square back to uniform
				map->square[i]->rect.setOutlineThickness(1);
				map->square[i]->rect.setOutlineColor(Color::Red);
				i = i-1;
				//changes the new square at index to differentiate where you're located
				map->square[i]->rect.setOutlineThickness(2);
				map->square[i]->rect.setOutlineColor(Color::Black);
			}
			break;
	case sf::Keyboard::Right: //move right, +1
		//if you're current location + 1 is a multiple of MAP_DIM you can't move right because that means you're already in the right column
		if((i+1)%MAP_DIM == 0){}
			else{
				//changes modified square back to uniform
				map->square[i]->rect.setOutlineThickness(1);
				map->square[i]->rect.setOutlineColor(Color::Red);
				i = i+1;
				//changes the new square at index to differentiate where you're located
				map->square[i]->rect.setOutlineThickness(2);
				map->square[i]->rect.setOutlineColor(Color::Black);

			}
			break;
		default:break;
	}
		//closes on window x
		if(game->event.type == Event::Closed) {
			game->window.close();
			}
		else{}
	
}

