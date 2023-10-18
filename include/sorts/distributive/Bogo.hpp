#ifndef BOGO_HPP
#define BOGO_HPP

#include "../../Sort.h"

/*
	Bogo Sort class

	Runs a Bogo sort
*/
class Bogo : public Sort {
public:
	explicit Bogo();				// Default Constructor

	explicit Bogo(short length);	// Primary Constructor

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
Bogo::Bogo() : Sort() {
	sort_info._sort_name = "Distribution Sorts: Bogo Sort";
}

// Primary Constructor
Bogo::Bogo(short length) : Sort(length) {
	sort_info._sort_name = "Distribution Sorts: Bogo Sort";
}

// Runs the sort
void Bogo::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	bool sorted = false;
	srand(time(nullptr));

	while (!sorted) {
		for (int i = 0; i < len; ++i) {
			int rInd = rand() % len;
			swap(i, rInd);
			usleep(delay);
		}

		sorted = true;

		for (int i = 1; i < len; ++i) {
			++sort_info._n_comparisons;
			if (arr[i] < arr[i - 1]) {
				sorted = false;
				break;
			}
		}
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Bogo::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // BOGO_HPP