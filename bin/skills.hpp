#ifndef SKILLS_HPP
#define SKILLS_HPP
#include<iostream>
#include<vector>
#include<iterator>
#include"square.hpp"
#include"map.hpp"
class skills{
public:
				virtual void use_skills() = 0;

};
//class for tunda skill
class tunda : public skills{
public:	void use_skill(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender);
};
//class for earthquake skill
class earthquake: public skills{
public:void use_skill(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender);
};
//class for fist skill
class fist :public skills{

public:	void use_skill(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender);

};


#endif
