#include"skills.hpp"
#include"map.hpp"
//thunder skill
//given an iterator to the attacker tile and an iterator to the defender tile
//iterate through defender

void growth::use_skill(faction attacker,vector<Square*>::iterator defender)
{
     //Only useable on unowned tiles
     if((*defender)->ownedBy != None) { return; }

	(*defender)->ownedBy = attacker;
     (*defender)->pop = 100;
     if(attacker == Christians) { defender[MAP_DIM]->rect.setFillColor(Color::Red); }
     else { defender[MAP_DIM]->rect.setFillColor(Color::Blue); }
}


//earth quake skill
//iterate to the edge of the map from selected tile
void earthquake::use_skill(faction attacker,vector<Square*>::iterator defender)
{
		for(int i = 0; (i<=MAP_DIM);i++)
		{
               if((*defender)->n+i >= MAP_DIM*MAP_DIM) { break; }
			(defender[i])->ownedBy=attacker;
               if(attacker == Christians) { defender[i]->rect.setFillColor(Color::Red); }
               else { defender[i]->rect.setFillColor(Color::Blue); }
		}
}


void fist::use_skill(faction attacker,vector<Square*>::iterator defender)
{
	(*defender)->ownedBy = None;
     (*defender)->rect.setFillColor(Color(255,255,255)); 
}

