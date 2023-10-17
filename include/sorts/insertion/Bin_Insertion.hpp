#ifndef BinInsertion_HPP
#define BinInsertion_HPP

#include "../../Sort.h"

/*
	Binary Insertion Sort class

	Runs a Binary Insertion sort
*/
class BinInsertion : public Sort {
public:
	explicit BinInsertion();				// Default Constructor

	explicit BinInsertion(short length);	// Primary Constructor

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
	int binSearch(int target, int low, int high);
};

// Default Constructor
BinInsertion::BinInsertion() : Sort() {
	sort_info._sort_name = "<_TEMPLATE_ CLASSIFICATION> Sorts: _TEMPLATE_ Sort";
}

// Primary Constructor
BinInsertion::BinInsertion(short length) : Sort(length) {
	sort_info._sort_name = "<_TEMPLATE_ CLASSIFICATION> Sorts: _TEMPLATE_ Sort";
}

// Runs the sort
void BinInsertion::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	for (int i = 1; i < len; ++i) {
		int j = i - 1;
		int target = arr[i];

		int target_pos = binSearch(target, 0, j);

		while (j >= target_pos) {
			++sort_info._n_comparisons;

			++sort_info._n_main_writes;
			arr[j + 1] = arr[j];
			usleep(delay);
			--j;
		}

		++sort_info._n_main_writes;
		arr[j + 1] = target;
		usleep(delay);
	}


	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void BinInsertion::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

int BinInsertion::binSearch(int target, int low, int high) {
	int m = (low + high) / 2;

	++sort_info._n_comparisons;
	if (target == arr[m]) {
		return m + 1;
	}

	++sort_info._n_comparisons;
	if (high <= low) {
		
		++sort_info._n_comparisons;
		if (target > arr[low]) {
			return low + 1;
		}
		else {
			return low;
		}
	}

	if (target > arr[m]) {
		return binSearch(target, m + 1, high);
	}
	return binSearch(target, low, m - 1);
}


#endif // BinInsertion_HPP