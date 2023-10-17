#ifndef ODD_EVEN
#define ODD_EVEN

#include "../../Sort.h"

/*
	Template Sort class

	Runs a ____ sort
*/
class OddEven : public Sort {
public:
	explicit OddEven();				// Default Constructor

	explicit OddEven(short length);	// Primary Constructor

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
OddEven::OddEven() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Comb Sort";
}

// Primary Constructor
OddEven::OddEven(short length) : Sort(length) {
	sort_info._sort_name = "Exchange Sorts: Comb Sort";
}

// Runs the sort
void OddEven::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	bool sorted = false;
	while (!sorted) {
		sorted = true;

		for (int i = 1; i < len - 1; i += 2) {

			++sort_info._n_comparisons;
			if (arr[i] > arr[i + 1]) {
				swap(i, i + 1);
				usleep(delay);
				sorted = false;
			}
		}

		for (int i = 0; i < len - 1; i += 2) {

			++sort_info._n_comparisons;
			if (arr[i] > arr[i + 1]) {
				swap(i, i + 1);
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

void OddEven::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // ODD_EVEN