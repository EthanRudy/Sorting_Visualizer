#ifndef SHOVE_HPP
#define SHOVE_HPP

#include "../../Sort.h"

/*
	Shove Sort class

	Runs a Shove sort
*/
class Shove : public Sort {
public:
	explicit Shove();				// Default Constructor

	explicit Shove(short length);	// Primary Constructor

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
Shove::Shove() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Shove Sort";
}

// Primary Constructor
Shove::Shove(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Shove Sort";
}

// Runs the sort
void Shove::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	int i = 0;
	while (i < len - 1) {

		++sort_info._n_comparisons;
		if (arr[i] > arr[i + 1]) {
			for (int j = i; j < len - 1; ++j) {
				++sort_info._n_comparisons;

				swap(j, j + 1);
				usleep(delay);
			}

			++sort_info._n_comparisons;
			if (i > 0) {
				--i;
			}
			continue;
		}
		++i;
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Shove::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // SHOVE_HPP