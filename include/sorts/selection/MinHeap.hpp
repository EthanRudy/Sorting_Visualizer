#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include "../../Sort.h"

/*
	Min Heap Sort class

	Runs a Min Heap sort
*/
class MinHeap : public Sort {
public:
	explicit MinHeap();				// Default Constructor

	explicit MinHeap(short length);	// Primary Constructor

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
MinHeap::MinHeap() : Sort() {
	sort_info._sort_name = "Selection Sorts: Min Heap Sort";
}

// Primary Constructor
MinHeap::MinHeap(short length) : Sort(length) {
	sort_info._sort_name = "Selection Sorts: Min Heap Sort";
}

// Runs the sort
void MinHeap::run() {
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

	reverse();

	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void MinHeap::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}


void MinHeap::heapify(int len, int i) {
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	++sort_info._n_comparisons;
	if (l < len && arr[l] < arr[smallest]) {
		smallest = l;
	}

	++sort_info._n_comparisons;
	if (r < len && arr[r] < arr[smallest]) {
		smallest = r;
	}

	++sort_info._n_comparisons;
	if (smallest != i) {
		swap(i, smallest);
		usleep(delay);

		heapify(len, smallest);
	}
}

#endif // MINHEAP_HPP