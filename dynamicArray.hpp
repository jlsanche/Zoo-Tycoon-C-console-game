/***********************************************************************************
 * File name: dynamicArray.hpp
 * Author: Jose L. Sanchez
 * Date: 10/14/17
 * Description: dynamicArray.cpp header files
 ***********************************************************************************/

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include "animal.hpp"

	class DynamicArray
	{
	private:
		Animal **pa;
		int length;
		int nextIndex;
	public:
		DynamicArray();
		virtual ~DynamicArray();
		Animal* operator[] (int index);
		void add(Animal* item);
		void removeAt(int index);
		int size();
		
	};

#endif
