#ifndef SKILLS_HPP
#define SKILLS_HPP
#include<iostream>
#include<vector>
#include<iterator>
#include"square.hpp"
#include"map.hpp"
#include "utilities.hpp"

class Skills{
public:
	virtual void use_skill(faction attacker, std::vector<Square*>::iterator defender) = 0;

};
//class for tunda skill
class growth : public Skills{
public:	void use_skill(faction attacker,std::vector<Square*>::iterator defender);
};
//class for earthquake skill
class earthquake: public Skills{
public:void use_skill(faction attacker,std::vector<Square*>::iterator defender);
};
//class for fist skill
class fist :public Skills{

public:	void use_skill(faction attacker,std::vector<Square*>::iterator defender);

};


#endif
