/***********************************************************************************
 * File name: animal.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: animal class--creates abstract animal constructor
 ***********************************************************************************/

#include "animal.hpp"
//constrcutor
Animal::Animal(int age, int cost, int numBabies, double payoff)
{

	Age = age;
	Cost = cost;
	NumberOfBabies = numBabies;
	Payoff = payoff;
}

int Animal::getAge()
{
	return Age;
}

int Animal::getCost()
{
	return Cost;
}

int Animal::getNumberOfBabies()
{
	return NumberOfBabies;
}

/***********************************************************************************
 * getPayoff function
 * Description: Calculates payoff--Tiger 20%, Penguin 10%, and Turle 5% of cost
 ***********************************************************************************/
int Animal::getPayoff()
{
	return (int)(Cost * Payoff);
}

int Animal::incAge()
{
	Age++;
	return Age;
}

Animal::~Animal()
{}

	