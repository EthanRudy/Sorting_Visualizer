#ifndef QUICK_HPP
#define QUICK_HPP

#include "../../Sort.h"

/*
	Quick Sort class

	Runs a Quick sort
*/
class Quick : public Sort {
public:
	explicit Quick();				// Default Constructor

	explicit Quick(short length);	// Primary Constructor

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
	void quickSort(int low, int high);

	int partition(int low, int high);
};

// Default Constructor
Quick::Quick() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Quick Sort";
}

// Primary Constructor
Quick::Quick(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Quick Sort";
}

// Runs the sort
void Quick::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	quickSort(0, len - 1);

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Quick::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

void Quick::quickSort(int low, int high) {
	if (low < high) {
		int p = partition(low, high);

		quickSort(low, p - 1);
		quickSort(p + 1, high);
	}
}

int Quick::partition(int low, int high) {
	int pivot = arr[high];

	int i = low - 1;

	for (int j = low; j <= high; ++j) {
		++sort_info._n_comparisons;
		if (arr[j] < pivot) {
			++i;
			swap(i, j);
			usleep(delay);
		}
	}
	swap(i + 1, high);
	usleep(delay);
	return i + 1;
}

#endif // QUICK_HPP