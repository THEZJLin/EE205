#include"skills.hpp"
#include"map.hpp"
//thunder skill
//given an iterator to the attacker tile and an iterator to the defender tile
//iterate through defender
void skills::tunda(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender)
{

	(*defender)->ownedBy=(*attacker)->ownedBy;
	defender[MAP_DIM]->ownedBy=(*attacker)->ownedBy;
}
//earth quake skill
//iterate to the edge of the map from selected tile
void skills::earthquake(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender)
{
	if()

	for(defender;defender < defender+ (MAP_DIM*MAP_DIM); defender += MAP_DIM)
	{
		(*defender)->ownedBy=(*attacker)->ownedBy;
	}

	for(defender;defender<defender+(MAP_DIM*MAP_DIM);defender += MAP_DIM)
	{
		(*defender)->ownedBy=(*attacker)->ownedBy;
	}
}
void skills::fist(std::vector<Square*>::iterator attacker,std::vector<Square*>::iterator defender)
{

}
