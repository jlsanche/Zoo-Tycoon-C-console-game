/***********************************************************************************
 * File name: tiger.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: tiger.cpp header files
 ***********************************************************************************/
#ifndef TIGER_H
#define TIGER_H

#include "animal.hpp"
#include <string>

class Tiger : public Animal
{
  public:
	Tiger(int age);
	int getFeedingCost();
	std::string getType();
	~Tiger();
};

#endif
