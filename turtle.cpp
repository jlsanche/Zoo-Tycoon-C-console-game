/***********************************************************************************
 * File name: turtle.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: Creates turtleobjects, inherits from animal class.  Constructor
 * params: age, $100 default cost, 10 babies, and 5% payoff of cost.
 ***********************************************************************************/
#include "animal.hpp"
#include "turtle.hpp"

Turtle::Turtle(int age) : Animal(age, 100, 10, .05)
{
}

//feeding cost that is 50% of the base cost
int Turtle::getFeedingCost()
{
	return (int)(BaseFoodCost * .50);
}

std::string Turtle::getType()
{
	return "Turtle";
}

Turtle::~Turtle()
{}
