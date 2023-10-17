#ifndef OPTIM_COCKTAIL_HPP
#define OPTIM_COCKTAIL_HPP

#include "../../Sort.h"

/*
	Optimized Cocktail Shaker Sort class

	Runs a Optimized Cocktail Shaker sort
*/
class OptimCocktail : public Sort {
public:
	explicit OptimCocktail();				// Default Constructor

	explicit OptimCocktail(short length);	// Primary Constructor

	/**
	* Runs the sort
	*/
	void run() override;

	/**
	* Checks the sort
	*/
	void check() override;
protected:

private:

};

// Default Constructor
OptimCocktail::OptimCocktail() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Optimized Cocktail Shaker Sort";
}

// Primary Constructor
OptimCocktail::OptimCocktail(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Optimized Cocktail Shaker Sort";
}

// Runs the sort
void OptimCocktail::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	for (int start = 0, end = len - 1; start < end;) {
		int consecutive = 1;

		for (int i = start; i < end; ++i) {

			++sort_info._n_comparisons;
			if (arr[i] > arr[i + 1]) {
				swap(i, i + 1);
				usleep(delay);
				consecutive = 1;
			}
			else {
				++consecutive;
			}
		}

		end -= consecutive;
		consecutive = 1;

		for (int i = end; i > start; --i) {
			if (arr[i - 1] > arr[i]) {
				swap(i, i - 1);
				usleep(delay);
				consecutive = 1;
			}
			else {
				++consecutive;
			}
		}

		start += consecutive;
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void OptimCocktail::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // OPTIM_COCKTAIL_HPP