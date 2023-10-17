#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../../Sort.h"

/*
	Circle Sort class

	Runs a Circle sort
*/
class Circle : public Sort {
public:
	explicit Circle();				// Default Constructor

	explicit Circle(short length);	// Primary Constructor

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
	bool circleRec(int low, int high);
};

// Default Constructor
Circle::Circle() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Circle Sort";
}

// Primary Constructor
Circle::Circle(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Circle Sort";
}

// Runs the sort
void Circle::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	while (circleRec(0, len - 1)) {}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Circle::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

bool Circle::circleRec(int low, int high) {
	bool swapped = false;

	if (low == high) { return false; }

	int l = low;
	int h = high;

	while (l < h) {

		++sort_info._n_comparisons;
		if (arr[l] > arr[h]) {
			swap(l, h);
			usleep(delay);
			swapped = true;
		}

		++l;
		--h;
	}

	++sort_info._n_comparisons;
	if (l == h) {

		++sort_info._n_comparisons;
		if (arr[l] > arr[h]) {
			swap(l, h);
			usleep(delay);
			swapped = true;
		}
	}

	int mid = (high - low) / 2;
	bool first = circleRec(low, low + mid);
	bool last = circleRec(low + mid + 1, high);

	return swapped || first || last;
}

#endif // CIRCLE_HPP