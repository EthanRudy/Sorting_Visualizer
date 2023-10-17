#ifndef INSERTION_HPP
#define INSERTION_HPP

#include "../../Sort.h"

/*
	Insertion Sort class

	Runs a Insertion sort
*/
class Insertion : public Sort {
public:
	explicit Insertion();				// Default Constructor

	explicit Insertion(short length);	// Primary Constructor

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
Insertion::Insertion() : Sort() {
	sort_info._sort_name = "Insertion Sorts: Insertion Sort";
}

// Primary Constructor
Insertion::Insertion(short length) : Sort(length) {
	sort_info._sort_name = "Insertion Sorts: Insertion Sort";
}

// Runs the sort
void Insertion::run() {
	sort_info.init_labels();

	while (!started) {}

	//sort_info._elapsed_timer.start();
	usleep(10000);
	shuffle();
	usleep(10000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;


	for (int i = 0; i < len; ++i) {

		++sort_info._n_comparisons;
		for (int j = i - 1; i > -1 && arr[j - 1] > arr[j]; --j) {
			swap(j, j - 1);
			usleep(delay);
		}
	}

	//sort_info._elapsed_timer.stop();

	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Insertion::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // INSERTION_HPP