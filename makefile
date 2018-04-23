
#***********************************************************************************
#*Program name: Project 2
#* Author: Jose Sanchez
#* Date: 10/19/2017
#* Description: makefile for Project 2 'Zoo Tycoon'
#***********************************************************************************/


CC=g++
CFLAGS=-c -Wall

all:output

output: main.o animal.o  penguin.o tiger.o turtle.o zoo.o dynamicArray.o
	$(CC) main.o animal.o penguin.o tiger.o turtle.o zoo.o dynamicArray.o   -o output

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

animal.o: animal.cpp
	$(CC) $(CFLAGS) animal.cpp

penguin.o: penguin.cpp
	$(CC) $(CFLAGS) penguin.cpp

tiger.o: tiger.cpp
	$(CC) $(CFLAGS) tiger.cpp

turtle.o: turtle.cpp
	$(CC) $(CFLAGS) turtle.cpp

zoo.o: zoo.cpp
	$(CC) $(CFLAGS) zoo.cpp

dynamicArray.o: dynamicArray.cpp
	$(CC) $(CFLAGS) dynamicArray.cpp

clean:
	rm *o output