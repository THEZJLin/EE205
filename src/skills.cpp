#include"skills.hpp"
#include"map.hpp"
//thunder skill
//given an iterator to the attacker tile and an iterator to the defender tile
//iterate through defender

void tunda::use_skill(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender)
{
	(*defender)->ownedBy=(*attacker)->ownedBy;
	//checks if the tiles are inbound
	//if out of bounds codes not gonna work
	if( (*defender)->n < ((MAP_DIM*MAP_DIM) - MAP_DIM) )
	{
		defender[MAP_DIM]->ownedBy = (*attacker)->ownedBy;
	}

}
//earth quake skill
//iterate to the edge of the map from selected tile
void earthquake::use_skill(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender)
{
	//earth quake for the christians
	if((*attacker)->ownedBy == Christians && (*attacker)->n >= (MAP_DIM*MAP_DIM -MAP_DIM))
	{
		for(int i = (*defender)->n; i<(MAP_DIM*MAP_DIM); i += MAP_DIM)
		{
			(*defender)->ownedBy=(*attacker)->ownedBy;
		}
	}
	//earthquake for the greeks
	if((*attacker)->ownedBy == Greeks && (*attacker)->n >(MAP_DIM))
	{
		for(int i=(*defender)->n;i>0; i -= MAP_DIM)
		{
			(*defender)->ownedBy=(*attacker)->ownedBy;
		}
	}
}
void fist::use_skill(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender)
{
	//makes sure no segmentation fault error
	if((*attacker)->n >=0 || (*attacker)-> n<MAP_DIM*MAP_DIM )
	(*defender)->ownedBy=(*attacker)->ownedBy;
}
