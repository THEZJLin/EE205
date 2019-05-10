#ifndef SKILLS_HPP
#define SKILLS_HPP
#include<iostream>
#include<vector>
#include<iterator>
#include"square.hpp"
#include"map.hpp"
class skills{
public:

				void tunda(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender);
				void earthquake(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender);
				void fist(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender);
};


#endif
