/***********************************************************************************
 * File name: penguin.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: penguin.cpp header files
 ***********************************************************************************/

#include "penguin.hpp"

/***********************************************************************************
 *constructor params: age, $1000 cost, 5 babies, and base feeding cost
 ***********************************************************************************/

Penguin::Penguin(int age) : Animal(age, 1000, 5, 10)
{
}

int Penguin::getFeedingCost()
{
	return Animal::BaseFoodCost;
}

std::string Penguin::getType()
{
	return "Penguin";
}

Penguin::~Penguin()
{}