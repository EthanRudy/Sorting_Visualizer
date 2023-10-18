#ifndef GRAVITY_HPP
#define GRAVITY_HPP

#include "../../Sort.h"

/*
	Gravity Sort class

	Runs a Gravity sort
*/
class Gravity : public Sort {
public:
	explicit Gravity();				// Default Constructor

	explicit Gravity(short length);	// Primary Constructor

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
Gravity::Gravity() : Sort() {
	sort_info._sort_name = "Distribution Sorts: Gravity Sort";
}

// Primary Constructor
Gravity::Gravity(short length) : Sort(length) {
	sort_info._sort_name = "Distribution Sorts: Gravity Sort";
}

// Runs the sort
void Gravity::run() {
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

	std::vector<std::vector<int>> beads;
	beads.resize(len);

	for (int i = 0; i < len; ++i) {
		beads[i].resize(max);
		std::fill(beads[i].begin(), beads[i].end(), 0);
	}

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < arr[i]; ++j) {
			++sort_info._n_aux_writes;
			beads[i][j] = 1;
		}
	}

	for (int i = 0; i < max; ++i) {
		int sum = 0;

		for (int j = 0; j < len; ++j) {
			sum += beads[j][i];
			++sort_info._n_aux_writes;
			beads[j][i] = 0;
		}
		for (int j = len - 1; j >= len - sum; --j) {
			++sort_info._n_aux_writes;
			beads[j][i] = 1;
		}
	}

	for (int i = 0; i < len; ++i) {
		int sum = 0;
		for (int j = 0; j < max; ++j) {
			sum += beads[i][j];
		}
		arr[i] = sum;
		usleep(delay);
		swap_a = i;
		swap_b = i;
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Gravity::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // GRAVITY_HPP