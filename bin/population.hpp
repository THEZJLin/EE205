#ifndef POPULATION_HPP
#define POPULATION_HPP
#include "map.hpp"
#include<iostream>
#include<vector>
#define MAXPOP 100;

class Population
			{

				public:
								int pop;
								float drate;
								float brate;
								int deaths;
								int births;
								int growth;
								int popleft;
								int popright;
								int poptop;
								int popbottom;

								Population(Map* map);





			};
#endif
