/***********************************************************************************
 * File name: tiger.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: Creates tiger objects, inherits from animal class.  Constructor
 * params: age, $10000 default cost, 1 baby, and 20% payoff of cost.
 ***********************************************************************************/

#include "tiger.hpp"

Tiger::Tiger(int age) : Animal(age, 1000, 1, .2)
{
}

//5 times the base cost
int Tiger::getFeedingCost()
{
	return BaseFoodCost * 5;
}

std::string Tiger::getType()
{
	return "Tiger";
}

Tiger::~Tiger()
{}
