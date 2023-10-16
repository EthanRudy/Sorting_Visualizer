#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include "../../Sort.h"

/*
	Template Sort class

	Runs a ____ sort
*/
class MaxHeap : public Sort {
public:
	explicit MaxHeap();				// Default Constructor

	explicit MaxHeap(short length);	// Primary Constructor

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
	* Heapify a subtree
	*/
	void heapify(int len, int i);
};

// Default Constructor
MaxHeap::MaxHeap() : Sort() {
	sort_info._sort_name = "Selection Sorts: Max Heap Sort";
}

// Primary Constructor
MaxHeap::MaxHeap(short length) : Sort(length) {
	sort_info._sort_name = "Selection Sorts: Max Heap Sort";
}

// Runs the sort
void MaxHeap::run() {
	sort_info.init_labels();
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	while (!started) {}

	//sort_info._elapsed_timer.start();

	for (int i = len / 2 - 1; i > -1; --i) {
		heapify(len, i);
	}

	for (int i = len - 1; i > 0; --i) {
		swap(0, i);
		usleep(delay);

		heapify(i, 0);
	}

	//sort_info._elapsed_timer.stop();

	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void MaxHeap::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}


void MaxHeap::heapify(int len, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	++sort_info._n_comparisons;
	if (l < len && arr[l] > arr[largest]) {
		largest = l;
	}

	++sort_info._n_comparisons;
	if (r < len && arr[r] > arr[largest]) {
		largest = r;
	}

	++sort_info._n_comparisons;
	if (largest != i) {
		swap(i, largest);
		usleep(delay);

		heapify(len, largest);
	}
}

#endif // MAXHEAP_HPP