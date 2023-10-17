#ifndef COCKTAIL_HPP
#define COCKTAIL_HPP

#include "../../Sort.h"

/*
	Cocktail Shaker Sort class

	Runs a Cocktail Shaker sort
*/
class Cocktail : public Sort {
public:
	explicit Cocktail();				// Default Constructor

	explicit Cocktail(short length);	// Primary Constructor

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
Cocktail::Cocktail() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Cocktail Shaker Sort";
}

// Primary Constructor
Cocktail::Cocktail(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Cocktail Shaker Sort";
}

// Runs the sort
void Cocktail::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	int start = 0;
	int end = len - 1;

	bool swapped = true;
	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			
			++sort_info._n_comparisons;
			if (arr[i] > arr[i + 1]) {
				swap(i, i + 1);
				usleep(delay);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}

		swapped = false;
		--end;

		for (int i = end - 1; i >= start; --i) {

			++sort_info._n_comparisons;
			if (arr[i] > arr[i + 1]) {
				swap(i, i + 1);
				usleep(delay);
				swapped = true;
			}
		}

		++start;
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Cocktail::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // COCKTAIL_HPP