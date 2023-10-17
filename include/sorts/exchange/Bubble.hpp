#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include "../../Sort.h"

/*
	Template Sort class

	Runs a ____ sort
*/
class Bubble : public Sort {
public:
	explicit Bubble();				// Default Constructor

	explicit Bubble(short length);	// Primary Constructor

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
Bubble::Bubble() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Bubble Sort";
}

// Primary Constructor
Bubble::Bubble(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Bubble Sort";
}

// Runs the sort
void Bubble::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	bool swapped;
	for (int i = 0; i < len - 1; ++i) {
		swapped = false;
		for (int j = 0; j < len - i - 1; ++j) {

			++sort_info._n_comparisons;
			if (arr[j] > arr[j + 1]) {
				swap(j, j + 1);
				usleep(delay);

				swapped = true;
			}
		}

		if (!swapped) { break; }
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Bubble::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // BUBBLE_HPP