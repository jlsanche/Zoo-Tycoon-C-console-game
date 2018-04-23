/***********************************************************************************
 * File name: penguin.hpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: penguin.cpp header files
 ***********************************************************************************/

#ifndef PENGUIN_H
#define PENGUIN_H

#include "animal.hpp"
#include <string>

class Penguin : public Animal
{
  public:
	Penguin(int age);
	int getFeedingCost();
	std::string getType();
	~Penguin();
};

#endif
