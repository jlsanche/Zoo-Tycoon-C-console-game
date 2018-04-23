/***********************************************************************************
 * File name: zoo.cpp
 * Author: Jose L. Sanchez
 * Date: 10/17/17
 * Description: This where zoo game happens.  User prompted to purchase animals
 * (1 or 2 ).  Animal inventory stored in dynamic arrays for each specified animal
 * user starts with 100k in bank. Starts with bonuses, profits to zero, and day to 1
 * Random events are intilaized.  animals can egt sick and die, attendance boom means
 * more profit.  Animals can be born,  User accumaltes payoff per animal  minus 
 * feeding cost based on type animal, or nothing can happen.  User is prompted to 
 * purchase animal. user prompted to end game or not.  If Zoo goes broke, Game ends.
 ***********************************************************************************/

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "tiger.hpp"
#include "animal.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "zoo.hpp"
#include <typeinfo>

Zoo::Zoo()
{
	moneyInBank = 0;
}

void Zoo::run()
{
	// seed random number generator
	srand((unsigned int)(time(0)));

	// starting account balance 100K
	moneyInBank = 100000;

	int numTigers = 0;
	int numPenguins = 0;
	int numTurtles = 0;

	std::cout << "How many tigers would you like to buy? " << std::endl;
	numTigers = getNumber(1, 2);

	for (int i = 0; i < numTigers; i++)

	{
		Tiger *tiger = new Tiger(1);
		animals.add(tiger);
		moneyInBank -= tiger->getCost();
	}

	std::cout << "How many penguins would you like to buy? " << std::endl;
	numPenguins = getNumber(1, 2);

	for (int i = 0; i < numPenguins; i++)
	{
		Penguin *penguin = new Penguin(1);
		animals.add(penguin);
		moneyInBank -= penguin->getCost();
	}

	std::cout << "How many turtles would you like to buy? " << std::endl;
	numTurtles = getNumber(1, 2);

	for (int i = 0; i < numTurtles; i++)
	{
		Turtle *turtle = new Turtle(1);
		animals.add(turtle);
		moneyInBank -= turtle->getCost();
	}

	int r = 0;
	int bonus = 0;
	int day = 1;
	int event = 0;
	std::string input;
	int profit = 0;

	std::cout << std::endl
			  << "Bank account balance: $" << moneyInBank << std::endl;

	// zoo loop
	do
	{
		bonus = 0;  // bonus for day
		profit = 0; // total payoff for day

		std::cout << "Day: " << day << std::endl;

		for (int i = 0; i < animals.size(); i++)
		{
			animals[i]->incAge();

			// feeding cost is subtracted from bank account balance
			moneyInBank -= animals[i]->getFeedingCost();
		}

		event = rand() % 4;

		//select Random Events:
		switch (event)
		{

		case 1:

			if (animals.size() > 0)
			{

				std::cout << "An animal is sick." << std::endl;

				// 1.Pick an animal at random to die
				r = rand() % animals.size();

				std::cout << "A " << animals[r]->getType() << " has died." << std::endl;

				//   2. Remove one animal from inventory (dynamic array )
				animals.removeAt(r);
			}

			break;

		case 2:

			std::cout << "Your zoo has experienced an attendance boom!" << std::endl;

			// Generate a random bonus for the day, $250 - $500 for each tiger in the zoo
			//Add bonus payoff for each tiger to total payoff of the day as a reward

			for (int i = 0; i < animals.size(); i++)
			{
				if (animals[i]->getType() == "Tiger")
				{
					bonus += (rand() % 250) + 500;
				}
			}

			std::cout << "You have racked up $" << bonus << " in bonuses thanks to the tigers!" << std::endl;
			break;

		// 3. An animal is born:
		case 3:

			std::cout << "An animal is born." << std::endl;

			// 1. Pick an animal at random to have a baby

			r = rand() % animals.size();

			std::cout << "Picking a random adult animal to birth a baby..." << std::endl;
			if (animals[r]->getAge() >= 3)
			{
				for (int j = 0; j < animals[r]->getNumberOfBabies(); j++)
				{
					if (animals[r]->getType() == "Tiger")
					{
						animals.add(new Tiger(0));
					}

					if (animals[r]->getType() == "Turtle")
					{
						animals.add(new Turtle(0));
					}

					if (animals[r]->getType() == "Penguin")
					{
						animals.add(new Penguin(0));
					}
				}

				break;
			}

			else
			{
				std::cout << "Random adult animal not available to give birth." << std::endl
						  << std::endl;
				std::cout << "Picking any available adult animal to give birth..." << std::endl;
				for (int i = 0; i < animals.size(); i++)
				{
					if (animals[i]->getAge() >= 3)
					{
						for (int j = 0; j < animals[i]->getNumberOfBabies(); j++)
						{
							if (animals[r]->getType() == "Tiger")
							{
								animals.add(new Tiger(0));
							}

							if (animals[r]->getType() == "Turtle")
							{
								animals.add(new Turtle(0));
							}

							if (animals[r]->getType() == "Penguin")
							{
								animals.add(new Penguin(0));
							}
						}
						break;
					}
				}
			}

			std::cout << "No animals born today." << std::endl;

			break;

		default:
			std::cout << "Nothing happened today." << std::endl;

		} // end switch

		// calculate the profit for the day based on inventory and their payoff.
		profit = 0;

		for (int i = 0; i < animals.size(); i++)
		{
			profit += animals[i]->getPayoff();
		}

		// If there is a bonus for the day, add to profit
		profit += bonus;

		// add profit to bank
		moneyInBank += profit;

		std::cout << "Would you like to buy an adult animal? (y/n): ";
		getline(std::cin, input);

		if (input == "y" || input == "Y")
		{
			std::cout << "What type of animal would you like to buy?" << std::endl;
			std::cout << "[T]iger t[U]rtle [P]enguin: ";
			getline(std::cin, input);

			if (input == "T" || input == "t")
			{
				Tiger *t = new Tiger(3);
				moneyInBank += t->getCost();
				animals.add(t);
			}

			else if (input == "U" || input == "u")
			{
				Turtle *t = new Turtle(3);
				moneyInBank += t->getCost();
				animals.add(t);
			}

			else if (input == "P" || input == "p")
			{
				Penguin *p = new Penguin(3);
				moneyInBank += p->getCost();
				animals.add(p);
			}

			else
				std::cout << "Invalid choice." << std::endl;
		}

		std::cout << std::endl
				  << "Bank account balance: $" << moneyInBank << std::endl;

		day++; // next day

		// prompt user whether to keep playing or end game.
		std::cout << "Do you want to end game? (y/n): ";
		getline(std::cin, input);

		if (input != "y" && input != "Y")
		{

			if (moneyInBank < 0)
			{
				std::cout << "You have no money left in bank." << std::endl;
				std::cout << "Game over!" << std::endl;
				input = "N";
			}
		}

	} while (input != "y" && input != "Y");

	std::cout << std::endl
			  << "Thank you for playing Zoo Tycoon!" << std::endl;

} // end run

/***********************************************************************************
 *input validation for numerical input.  Uses stringstream to convert int to
 string -- if valid--converted back to int if within range (1-2).
 ***********************************************************************************/
int Zoo::getNumber(int min, int max)
{
	std::string input;
	int x = 0;

	do
	{
		std::cout << "Enter a number " << min << " to " << max << ": ";
		getline(std::cin, input);
		std::istringstream ss(input);
		ss >> x;
		if (!ss)
			x = min - 1;
	} while (x < min || x > max);

	return x;
}

Zoo::~Zoo()
{
	for( int i = 0; i < animals.size(); i++)
	{
		delete animals[i];
		
	}


}
