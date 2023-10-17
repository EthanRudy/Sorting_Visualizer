#ifndef OPTIM_GNOME_HPP
#define OPTIM_GNOME_HPP

#include "../../Sort.h"

/*
	Optimized Gnome Sort class

	Runs a Optimized Gnome sort
*/
class OptimGnome : public Sort {
public:
	explicit OptimGnome();				// Default Constructor

	explicit OptimGnome(short length);	// Primary Constructor

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
OptimGnome::OptimGnome() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Optimized Gnome Sort";
}

// Primary Constructor
OptimGnome::OptimGnome(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Optimized Gnome Sort";
}

// Runs the sort
void OptimGnome::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	for (int i = 1; i < len; ++i) {
		++sort_info._n_comparisons;

		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			++sort_info._n_comparisons;

			swap(j, j - 1);
			usleep(delay);
			--j;
		}
	}
	

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void OptimGnome::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // OPTIM_GNOME_HPP