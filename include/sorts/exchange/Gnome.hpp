#ifndef GNOME_HPP
#define GNOME_HPP

#include "../../Sort.h"

/*
	Gnome Sort class

	Runs a Gnome sort
*/
class Gnome : public Sort {
public:
	explicit Gnome();				// Default Constructor

	explicit Gnome(short length);	// Primary Constructor

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
Gnome::Gnome() : Sort() {
	sort_info._sort_name = "Exchange Sorts: Gnome Sort";
}

// Primary Constructor
Gnome::Gnome(short length) : Sort(length) {
	sort_info._sort_name = "<Exchange Sorts: Gnome Sort";
}

// Runs the sort
void Gnome::run() {
	sort_info.init_labels();

	while (!started) {}

	usleep(500000);
	shuffle();
	usleep(500000);
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	//sort_info._elapsed_timer.start();

	for (int i = 0; i < len;) {

		++sort_info._n_comparisons;
		if (i == 0 || arr[i] > arr[i - 1]) {
			++i;
		}
		else {
			swap(i, i - 1);
			usleep(delay);

			--i;
		}
	}

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Gnome::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // GNOME_HPP