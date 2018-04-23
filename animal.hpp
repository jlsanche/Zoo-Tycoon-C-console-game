/***********************************************************************************
 * File name: animal.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: animal.cpp header files
 ***********************************************************************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{

  private:
	int Age;
	int Cost;
	int NumberOfBabies;

  public:
	const int BaseFoodCost = 10; //set as constant $10 base cost

  private:
	double Payoff;

  public:
	Animal(int age, int cost, int numberBabies, double payoff);

	int getAge();
	int incAge();
	int getCost();
	int getNumberOfBabies();
	virtual int getFeedingCost() = 0; //pure virtual
	int getPayoff();
	virtual std::string getType() = 0; //pure virtual
	virtual ~Animal();
};

#endif
