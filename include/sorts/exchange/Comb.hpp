#ifndef COMB_HPP
#define COMB_HPP

#include "../../Sort.h"

/*
	Comb Sort class

	Runs a Comb sort
*/
class Comb : public Sort {
public:
	explicit Comb();				// Default Constructor

	explicit Comb(short length);	// Primary Constructor

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
Comb::Comb() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Comb Sort";
}

// Primary Constructor
Comb::Comb(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Comb Sort";
}

// Runs the sort
void Comb::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	int gap = len;
	float shrink_fac = 1.3f;
	bool sorted = false;

	while (!sorted) {
		gap = floor(gap / shrink_fac);
		if (gap <= 1) {
			gap = 1;
			sorted = true;
		}

		for (int i = 0; i + gap < len; ++i) {

			++sort_info._n_comparisons;
			if (arr[i] > arr[i + gap]) {
				swap(i, i + gap);
				usleep(delay);
				sorted = false;
			}
		}
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Comb::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // COMB_HPP