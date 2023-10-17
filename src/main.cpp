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
#include "../include/sorts/insertion/Tree.hpp"
#include "../include/sorts/insertion/Bin_Insertion.hpp"

#include "../include/sorts/exchange/Gnome.hpp"
#include "../include/sorts/exchange/Bubble.hpp"
#include "../include/sorts/exchange/Circle.hpp"
#include "../include/sorts/exchange/Cocktail.hpp"
#include "../include/sorts/exchange/Comb.hpp"
#include "../include/sorts/exchange/Odd_Even.hpp"
#include "../include/sorts/exchange/Shove.hpp"
#include "../include/sorts/exchange/Optim_Gnome.hpp"
#include "../include/sorts/exchange/Optim_Bubble.hpp"
#include "../include/sorts/exchange/Optim_Cocktail.hpp"
#include "../include/sorts/exchange/Quick.hpp"

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
	tree,				DONE
	bin_insertion,		DONE

	// Exchange
	gnome,				DONE
	bubble,				DONE
	circle,				DONE
	cocktail,			DONE
	comb,				DONE
	odd_even,			DONE
	shove,				DONE
	optim_gnome,		DONE
	optim_bubble,		DONE
	optim_cocktail,		DONE
	quick,				DONE

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

	// Hybrid
	Intro
*/

// Number of sorts availible to the user
const short N_SORTS = 34;

// Polymorphic Sort list. Holds an instance of each available sort
Sort* sort_list[N_SORTS] = {
	new Selection,
	new Smooth,
	new MinHeap,
	new MaxHeap,
	new Cycle,
	new Insertion,
	new Shell,
	new Tree,
	new BinInsertion,
	new Gnome,
	new Bubble,
	new Circle,
	new Cocktail,
	new Comb,
	new OddEven,
	new Shove,
	new OptimGnome,
	new OptimBubble,
	new OptimCocktail,
	new Quick,
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
		"(0)  Selection\n"
		"(1)  Smooth\n"
		"(2)  Min Heap\n"
		"(3)  Max Heap\n"
		"(4)  Cycle\n"
		"(5)  Insertion\n"
		"(6)  Shell\n"
		"(7)  Tree\n"
		"(8)  Binary Insertion\n"
		"(9)  Gnome\n"
		"(10) Bubble\n"
		"(11) Circle\n"
		"(12) Cocktail\n"
		"(13) Comb\n"
		"(14) Odd-Even\n"
		"(15) Shove\n"
		"(16) Optimized Gnome\n"
		"(17) Optimized Bubble\n"
		"(18) Optimized Cocktail\n"
		"(19) Quick\n";

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