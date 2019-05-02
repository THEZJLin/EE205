#include"population.hpp"

Population::Population(Map* map)
{
	//iterate through the map
	int i = 0;
	for(vector<Square*>::iterator it = map->square.begin(); it!=map->square.end(); ++it)
	{
		std::cout<< "i ="<< i <<"pop =" <<pop <<"births ="<<births <<std::endl;
		pop = (*it)->population;
		if(pop!=0){
			map->square[i]->rect.setFillColor(Color::Red);

		}
	//	std::cout<<"c"<<std::endl;
		if(i<48){
		//	std::cout<<"c"<<std::endl;
			popright = (*(it+1))->population;
		}

		if(i>1)popleft = it[-1]->population;
		if(i>7)poptop = it[-7]->population;
		if(i<36)popbottom = it[7]->population;

		drate = (*it)->death;
		brate = (*it)->birth;
		//if population is not at max
		if(pop != 0)
		{
			//calculate births
			births =(float)pop*brate;
			//calculates deaths
			deaths = (float)pop*drate;
			pop = pop+births;
			//updates deaths

			//if the population is at max
			if(pop > 100)
			{
				if(i>=1)
				{
					(*(it-1))->population =(pop-100);
					pop = 100;

				}

				if(popright < popleft && popright < poptop && popright<popbottom && i<1)
				{
					//move pop to right
					(it[1])->population = pop - MAXPOP;
					pop = MAXPOP;
				}
				if(i < 36  && popbottom < poptop && popbottom<popright && popbottom<popleft)
				{
					//move pop to bottom
					it[7]->population = pop - MAXPOP;
					pop = MAXPOP;
				}
				if(i > 7 && poptop <popbottom && poptop< popleft && poptop < popright)
				{
					//move pop to top
					(it[-7])->population = pop - MAXPOP;
					pop = MAXPOP;
				}
				(*it)->population = pop;
			}
		}
i++;	}
}
