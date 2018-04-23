/***********************************************************************************
 * File name: main.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: client for Zoo Tycoon
 ***********************************************************************************/

#include <iostream>
#include "dynamicArray.hpp"
#include "zoo.hpp"

int main()
{
    std::cout << std::endl;
    std::cout << "********** Welcome to ***********" << std::endl;
    std::cout << "*          Zoo Tycoon!          *" << std::endl;
    std::cout << "*********************************" << std::endl;
    std::cout << std::endl;

    Zoo zoo;

    zoo.run();

    return 0;
}