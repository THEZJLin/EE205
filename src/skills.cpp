#include"skills.hpp"
#include"map.hpp"
//thunder skill
//given an iterator to the attacker tile and an iterator to the defender tile
//iterate through defender

void tunda::use_skill(faction attacker,vector<Square*>::iterator defender)
{
	(*defender)->ownedBy = attacker;
	//checks if the tiles are inbound
	//if out of bounds codes not gonna work
	if( (*defender)->n < ((MAP_DIM*MAP_DIM) - MAP_DIM) )
	{
		defender[MAP_DIM]->ownedBy = attacker;
	}

}
//earth quake skill
//iterate to the edge of the map from selected tile
void earthquake::use_skill(faction attacker,vector<Square*>::iterator defender)
{
	//earth quake for the christians
	if(attacker == Christians && (*defender)->n >= (MAP_DIM*MAP_DIM -MAP_DIM))
	{
		for(int i = (*defender)->n; i<(MAP_DIM*MAP_DIM); i += MAP_DIM)
		{
			(*defender)->ownedBy=attacker;
		}
	}
	//earthquake for the greeks
	if(attacker == Greeks && (*defender)->n >(MAP_DIM))
	{
		for(int i=(*defender)->n;i>0; i -= MAP_DIM)
		{
			(*defender)->ownedBy=attacker;
		}
	}
}
void fist::use_skill(faction attacker,vector<Square*>::iterator defender)
{
	//makes sure no segmentation fault error
	if((*defender)->n >=0 || (*defender)-> n<MAP_DIM*MAP_DIM )
	(*defender)->ownedBy = attacker;
}
