#ifndef OPTIM_BUBBLE_HPP
#define OPTIM_BUBBLE_HPP

#include "../../Sort.h"

/*
	Optimized Bubble Sort class

	Runs a Optimized Bubble sort
*/
class OptimBubble : public Sort {
public:
	explicit OptimBubble();				// Default Constructor

	explicit OptimBubble(short length);	// Primary Constructor

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
OptimBubble::OptimBubble() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Optimized Bubble Sort";
}

// Primary Constructor
OptimBubble::OptimBubble(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Optimized Bubble Sort";
}

// Runs the sort
void OptimBubble::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	int n = len;
	while (!(n <= 1)) {
		int newN = 0;
		for (int i = 1; i < n; ++i) {

			++sort_info._n_comparisons;
			if (arr[i - 1] > arr[i]) {
				swap(i, i - 1);
				usleep(delay);
				newN = i;
			}
		}
		n = newN;
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void OptimBubble::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // OPTIM_BUBBLE_HPP