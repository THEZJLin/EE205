#include "utilities.hpp"


int pCalculate(int currentPopulation, float growthFactor){
	float newPopulation;
	float newPopulationRound
	//When a float and an int multiply and the ouotput is an int, it always rounds down
	int newPopulationInt;

	//Gets the decimal part of the population
	newPopulation = currentPopulation * growthfactor;
	newPopulationRound = ((newPopulation + 1) - newPopulation);

	//Round down if  tenths digit is less than .5
	if (newPopulationRound < .5){
		newPopulationInt = currentPopulation * growthfactor;
	}
	//Round up if tenths digits is more than .5
	if (newPopulationRound >= .5_){
		newPopulationInt = newPopulation + newPopulationRound;
	}
	return NewPopulationInt;
}