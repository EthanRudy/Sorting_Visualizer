#ifndef SMOOTH_HPP
#define SMOOTH_HPP

#include "../../Sort.h"
#include <vector>

/*
	Smooth Sort class

	Runs a smooth sort
*/
class Smooth : public Sort {
public:
	explicit Smooth();				// Default Constructor

	explicit Smooth(short length);	// Primary Constructor

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
	/**
	* Defines the leonardo numbers
	*/
	int leonardo(int n);

	/**
	* Builds the heaps
	*/
	void heapify(int start, int end);
};

// Default Constructor
Smooth::Smooth() : Sort() {
	sort_info._sort_name = "Selection Sorts: Smooth Sort";
}

// Primary Constructor
Smooth::Smooth(short length) : Sort(length) {
	sort_info._sort_name = "Selection Sorts: Smooth Sort";
}

// Runs the sort
void Smooth::run() {
	sort_info.init_labels();
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	while (!started) {}

	//sort_info._elapsed_timer.start();

	int p = len - 1;
	int q = p;
	int r = 0;

	while (p > 0) {
		
		++sort_info._n_comparisons;
		if ((r & 3) == 0) {
			heapify(r, q);
		}
		
		++sort_info._n_comparisons;
		if (leonardo(r) == p) {
			++r;
		}
		else {
			--r;
			q -= leonardo(r);
			heapify(r, q);
			q = r - 1;
			++r;
		}

		swap(0, p);
		usleep(delay);
		--p;
	}

	for (int i = 0; i < len - 1; ++i) {
		for (int j = i + 1; j > 0 && arr[j] < arr[j - 1]; --j) {
			swap(j, j - 1);
			usleep(delay);
		}
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}


void Smooth::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}



// Defines the leonardo numbers
int Smooth::leonardo(int n) {
	++sort_info._n_comparisons;
	if (n < 2) {
		return 1;
	}
	return leonardo(n - 1) + leonardo(n - 2) + 1;
}


// Builds the heaps
void Smooth::heapify(int start, int end) {
	int i = start;
	int j = 0;
	int k = 0;

	while (k < end - start + 1) {
		++sort_info._n_comparisons;
		if (k & 0xAAAAAAAA) {
			j += i;
			i >>= 1;
		}
		else {
			i += j;
			j >>= 1;
		}
		++k;
	}

	while (i > 0) {
		j >>= 1;
		k = i + j;
		while (k < end) {

			++sort_info._n_comparisons;
			if (arr[k] > arr[k - 1]) {
				break;
			}

			swap(k, k - i);
			usleep(delay);

			k += i;
		}
		i = j;
	}
}

#endif // SMOOTH_HPP