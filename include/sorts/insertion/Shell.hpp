#ifndef SHELL_HPP
#define SHELL_HPP

#include "../../Sort.h"

/*
	Insertion Sort class

	Runs a Insertion sort
*/
class Shell : public Sort {
public:
	explicit Shell();				// Default Constructor

	explicit Shell(short length);	// Primary Constructor

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
Shell::Shell() : Sort() {
	sort_info._sort_name = "Insertion Sorts: Shell Sort";
}

// Primary Constructor
Shell::Shell(short length) : Sort(length) {
	sort_info._sort_name = "Insertion Sorts: Shell Sort";
}

// Runs the sort
void Shell::run() {
	sort_info.init_labels();
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	while (!started) {}

	//sort_info._elapsed_timer.start();

	for (int gap = len / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < len; ++i) {
			int t = arr[i];
			int j;				// OUt of the loop so we can use it later
			for (j = i; j >= gap && arr[j - gap] > t; j -= gap) {
				++sort_info._n_comparisons;
				
				++sort_info._n_main_writes;
				arr[j] = arr[j - gap];
				swap_a = j;
				swap_b = j - gap;
				usleep(delay);
			}

			++sort_info._n_main_writes;
			arr[j] = t;
			swap_a = j;
			swap_b = i;	// From t == arr[i];
			usleep(delay);
		}
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Shell::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // _TEMPLATE__HPP