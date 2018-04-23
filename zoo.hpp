
/***********************************************************************************
 * File name: zoo.hpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: zoo.cpp header files
 ***********************************************************************************/
#ifndef ZOO_H
#define ZOO_H

#include "dynamicArray.hpp"
#include <iostream>
#include <string.h>
#include <string.h>

class Zoo
{
  private:
	double moneyInBank;
	DynamicArray animals;

  public:
	Zoo();
	void run();
	int getNumber(int min, int max);
  virtual ~Zoo();
	
};

#endif
