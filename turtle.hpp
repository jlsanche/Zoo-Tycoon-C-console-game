/***********************************************************************************
 * File name: turtle.hpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: turtle.cpp header files
 ***********************************************************************************/

#ifndef TURTLE_H
#define TURTLE_H

#include "animal.hpp"

#include <string>

class Turtle : public Animal
{
  public:
	Turtle(int age);
	int getFeedingCost();
	std::string getType();
	~Turtle();

};

#endif
