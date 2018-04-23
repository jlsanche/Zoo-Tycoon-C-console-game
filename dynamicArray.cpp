/***********************************************************************************
 * File name: dynamicArray.cpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: Creates dynamically created arrays to store animal objects, returns 
 * array, and remove objects in array.
 ***********************************************************************************/

#include "dynamicArray.hpp"

/***********************************************************************************
 *Constructor with a defualt array of size 10 to hold animal objects
 ***********************************************************************************/
DynamicArray::DynamicArray()
{
	pa = new Animal *[10];
	length = 10;
	nextIndex = 0;
}

DynamicArray::~DynamicArray()
{
	delete[] pa;
}

/***********************************************************************************
 *function with param. to animal objects to array
 *if array full, double space.
 *cited:https://stackoverflow.com/questions/12032222/how-to-dynamically
 -increase-the-array-size
 ***********************************************************************************/
void DynamicArray::add(Animal *item)
{
	Animal **temp = 0; //allocate new array and store in temp pointer
	if (nextIndex == length)
	{
		length = length + 10;
		temp = new Animal *[length];
		for (int i = 0; i < nextIndex; i++) //copy previous values
		{
			temp[i] = pa[i]; //copy
		}

		delete[] pa; //delete temp array
		pa = temp;
	}

	pa[nextIndex++] = item; //point to new array
}
/***********************************************************************************
 *removes  animal object in array
 ***********************************************************************************/

void DynamicArray::removeAt(int index)
{
	Animal **temp = 0; ////allocate new array and store in temp pointer
	temp = new Animal *[length - 1];

	for (int i = 0; i < index; i++)
	{
		temp[i] = pa[i]; //copy over elements
	}
	for (int j = index; j < length - 1; ++j)
	{
		temp[j] = pa[j + 1];
	}

	delete[] pa; //delete temp array
	pa = temp;
	length--; //decrease array size
	nextIndex--;
}
/***********************************************************************************
 *overlaoded [] to return dereferenced index elements 
 cited: http://www.cplusplus.com/forum/beginner/28033/
 ***********************************************************************************/

Animal *DynamicArray::operator[](int index)
{
	return pa[index];
}

int DynamicArray::size()
{
	return nextIndex;
}
