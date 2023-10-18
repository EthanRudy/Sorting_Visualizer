#ifndef COUNTING_HPP
#define COUNTING_HPP

#include "../../Sort.h"

/*
	Counting Sort class

	Runs a Counting sort
*/
class Counting : public Sort {
public:
	explicit Counting();				// Default Constructor

	explicit Counting(short length);	// Primary Constructor

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
Counting::Counting() : Sort() {
	sort_info._sort_name = "Distribution Sorts: Counting Sort";
}

// Primary Constructor
Counting::Counting(short length) : Sort(length) {
	sort_info._sort_name = "Distribution Sorts: Counting Sort";
}

// Runs the sort
void Counting::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	int max = arr[0];

	for (int i = 1; i < len; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	sort_info._n_aux_writes += max + 1;
	std::vector<int> count(max + 1, 0);
	sort_info._n_aux_writes += len;
	std::vector<int> output(len);

	/* Yes I could skip this but in reality you may have duplicate indices*/
	for (int i = 0; i < len; ++i) {
		int j = arr[i];
		++count[j];
		++sort_info._n_aux_writes;
	}

	for (int i = 1; i < max; ++i) {
		count[i] += count[i - 1];
		++sort_info._n_aux_writes;
	}

	for (int i = len - 1; i > -1; --i) {
		int j = arr[i];
		--count[j];
		output[count[j]] = arr[i];
		sort_info._n_aux_writes += 2;
	}

	for (int i = 0; i < len; ++i) {
		arr[i] = output[i];
		usleep(delay);
		++sort_info._n_main_writes;
		swap_a = i;
		swap_b = i;
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Counting::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // COUNTING_HPP