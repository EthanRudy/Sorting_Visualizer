/*
	COPYRIGHT
*/

#ifndef SELECTION_HPP
#define SELECTION_HPP

#include "../../Sort.h"

/*
	Selection Sort class

	Runs a selection sort
*/
class Selection : public Sort {
public:
	explicit Selection();				// Default Constructor

	explicit Selection(short length);	// Primary Constructor

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
Selection::Selection() : Sort() { 
	sort_info._sort_name = "Selection Sorts: Selection Sort";
}

// Primary Constructor
Selection::Selection(short length) : Sort(length) { 
	sort_info._sort_name = "Selection Sorts: Selection Sort";
}

// Runs the sort
void Selection::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	for (short i = 0; i < len - 1; ++i) {
		short k = i;
		for (short j = i + 1; j < len; ++j) {

			++sort_info._n_comparisons;
			if (arr[j] < arr[k]) {
				k = j;
			}
		}

		++sort_info._n_comparisons;
		if (k != i) {
			swap(i, k);
			usleep(delay);
		}
	}

	//sort_info._elapsed_timer.stop();
	swap_a = -1;
	swap_b = -1;

	usleep(1000);

	check();

	finished = true;
}

// Checks the sort
void Selection::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_a = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // SELECTION_H