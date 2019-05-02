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
}	

void Movement::draw(){
		game->window.clear();
		for(std::vector<Square*>::iterator it=map->square.begin();it!=map->square.end();++it) {
		game->window.draw((*it)->rect);
		}	
}
void Movement::update(){

}
void Movement::handleInput(){
	sf::Keyboard::Key x;
	if(game->event.type == Event::KeyPressed){
	x = game->event.key.code;
	}
	else{}
	switch(x){ //vector of square pointers
	case sf::Keyboard::Up: //move up, -n
		if(i <= MAP_DIM-1){}
			else{
				map->square[i]->rect.setFillColor(Color::Yellow); 
				i = i - MAP_DIM;
				map->square[i]->rect.setFillColor(Color::Black);
			}
			break;
	case sf::Keyboard::Down: //move down, +n
		if(i >((MAP_DIM * MAP_DIM) - 1 - MAP_DIM)){}
			else{
				map->square[i]->rect.setFillColor(Color::Yellow);
				i = i + MAP_DIM;
				map->square[i]->rect.setFillColor(Color::Black);
			}	
			break;
	case sf::Keyboard::Left: //move left, -1
		//if current a multiple of 20, don't do anything
		if((i)%MAP_DIM == 0){}
			else{
				map->square[i]->rect.setFillColor(Color::Yellow);
				i = i-1;
				map->square[i]->rect.setFillColor(Color::Black);
			}
			break;
	case sf::Keyboard::Right: //move right, +1
		//if current +1 is a multiple of 20, don't do anything
		if((i+1)%MAP_DIM == 0){}
			else{
				map->square[i]->rect.setFillColor(Color::Yellow);
				i = i+1;
				map->square[i]->rect.setFillColor(Color::Black);

			}
			break;
		default:break;
	}
		if(game->event.type == Event::Closed) {
			game->window.close();
			}
		else{}
	
}

