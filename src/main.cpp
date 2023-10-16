/*
	COPYRIGHT
*/

#include <iostream>
#include <string>
#include <climits>

#include "../include/sorts/selection/Selection.hpp"
#include "../include/sorts/selection/Smooth.hpp"
#include "../include/sorts/selection/MinHeap.hpp"
#include "../include/sorts/selection/MaxHeap.hpp"
#include "../include/sorts/selection/Cycle.hpp"

#include "../include/sorts/insertion/Insertion.hpp"
#include "../include/sorts/insertion/Shell.hpp"

#include "../include/Visualizer.h"

// https://developer.lsst.io/cpp/style.html

/*
	// Selection
	selection,			DONE
	smooth,				DONE
	min_heap,			DONE
	max_heap,			DONE
	cycle,				DONE		

	// Insertion
	insertion,			DONE
	shell,				DONE
	tree,
	bin_insertion,

	// Exchange
	gnome,
	bin_gnome,
	bubble,
	circle,
	cocktail,
	comb,
	odd_even,
	shove,
	optim_gnome,
	optim_bubble,
	optim_cocktail,
	quick,
	stable_quick,

	// Distribution
	american_flag,
	bin_quick,
	bogo,
	gravity,
	counting,
	LSD_radix,
	MSD_radix,
	pigeonhole,
	shatter,
	time,

	// Concurrent
	bitonic,

	// Merge
	merge,
	quad, 
*/

// Number of sorts availible to the user
const short N_SORTS = 35;

// Polymorphic Sort list. Holds an instance of each available sort
Sort* sort_list[N_SORTS] = {
	new Selection,
	new Smooth,
	new MinHeap,
	new MaxHeap,
	new Cycle,
	new Insertion,
	new Shell,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
	new Sort,
};

/**
* Gets input within the specified range (inclusive)
* 
* @param Text prompt
* @param Minimum value
* @param Maximum value
* 
* @return Valid input
*/
int getInput(std::string prompt, int min, int max);


/**
* Is Numerical
* 
* @param String to be checked
* 
* @return T/F representing if the string is numeric
*/
bool isNumeric(const std::string& str);


/**
* Main Program loop
*/
int main() {

	std::string sort_prompt = "Enter Sort Index:\n"
		"(0) Selection\n"
		"(1) Smooth\n"
		"(2) Min Heap\n"
		"(3) Max Heap\n"
		"(4) Cycle\n"
		"(5) Insertion\n"
		"(6) Shell\n";

	// What they'd like to run
	short sort_choice = getInput(sort_prompt, 0, N_SORTS - 1);

	// How many values
	short n_values = getInput("Enter number of elements:", 8, SHRT_MAX);

	// How much delay
	int delay = getInput("Enter delay (microseconds):", 0, 1000000);

	Sort* chosen = sort_list[sort_choice];
	chosen->setLength(n_values);
	chosen->setDelay(delay);

	Visualizer visualizer(chosen);

	visualizer.init_window();
	visualizer.run();
}


// Gets input within the specified range (inclusive)
int getInput(std::string prompt, int min, int max) {
	std::string choice_str;
	bool is_num = false;
	bool is_ranged = false;

	while (!is_num || !is_ranged) {
		std::cout << prompt << "\n > ";
		std::cin >> choice_str;

		is_num = isNumeric(choice_str);
		
		if (!is_num) {
			prompt = "Please enter only numerical digits!";
		} else {
			int choice = std::stoi(choice_str);
			is_ranged = (choice >= min) && (choice <= max);
			if (!is_ranged) { 
				prompt = "Please enter a number in the range [" + 
										std::to_string(min) + ", " + 
										std::to_string(max) + "]!"; 
			}
		}
	}

	return std::stoi(choice_str);
}


// Is Numerical
bool isNumeric(const std::string& str) {
	for (char c : str) {
		if (c < 48 || c > 57) { 
			return false; 
		}
	}
	return true;
}