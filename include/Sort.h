/*
	COPYRIGHT
*/

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <random>
#include <time.h>
#include <thread>
#include "Sort_Information.h"
#include <windows.h>

/**
 * Parent class for all sort types
 * 
 * Manages the base components used in all sorts
 */
class Sort {
public:
	explicit Sort();				// Default Constructor

	explicit Sort(short length);	// Primary Constructor

	virtual ~Sort();				// Deconstructor

	/**
	* Randomly shuffles the array
	*/
	void shuffle();

	/**
	* Set Delay
	* 
	* @param delay (in microseconds)
	*/
	void setDelay(int delay);

	/**
	* Set Length
	* 
	* @param length
	*/
	void setLength(short length);

	/**
	* Get Length
	* 
	* @return length
	*/
	short getLength();

	/**
	* Get Element
	* 
	* @param index to get
	* 
	* @return element at index
	*/
	short get(short index);

	/**
	* Prints values to the console
	*/
	void printArr() const;

	/**
	* Runs the sort
	*/
	virtual void run();

	/** Checks the sort
	*/
	virtual void check();

	bool started;		// Bool to hang the thread before we want to start
	bool finished;		// Bool used to join the thread after the sort ends

	short swap_a;		// First swapped index
	short swap_b;		// Second swapped index

	short check_ind;	// Used to display the check visual

	SortInformation sort_info;	// Information holder
protected:
	short len;			// Length of the array of values
	short* arr;			// Array of values

	int delay;		// Delay between operations

	/**
	* Swaps two array indices (A & B)
	* 
	* @param Index A
	* @param Index B
	*/
	void swap(short a, short b);

	/**
	* Replacement for not having unix function
	* https://stackoverflow.com/questions/5801813/c-usleep-is-obsolete-workarounds-for-windows-mingw
	* 
	* @param usec (microseconds)
	*/
	void usleep(__int64 usec);
};

#endif // SORT_H