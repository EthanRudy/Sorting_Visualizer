#ifndef _TEMPLATE__HPP
#define _TEMPLATE__HPP

#include "../../Sort.h"

/*
	Template Sort class

	Runs a ____ sort
*/
class _Template_ : public Sort {
public:
	explicit _Template_();				// Default Constructor

	explicit _Template_(short length);	// Primary Constructor

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
_Template_::_Template_() : Sort() {
	sort_info._sort_name = "<_TEMPLATE_ CLASSIFICATION> Sorts: _TEMPLATE_ Sort";
}

// Primary Constructor
_Template_::_Template_(short length) : Sort(length) {
	sort_info._sort_name = "<_TEMPLATE_ CLASSIFICATION> Sorts: _TEMPLATE_ Sort";
}

// Runs the sort
void _Template_::run() {
	sort_info.init_labels();
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	while (!started) {}

	//sort_info._elapsed_timer.start();

	/**
	* Sorting algorithm goes here!
	* 
	* Tips
	* 
	* use "usleep(delay)" whenever swapping indices, this is how the sort is slowed
	* 
	* when swapping, use swap(index a, index b). incrementation of some of the 
	* counters is handled there
	* 
	* If you do any comparisions, inrement "_n_comparisons"
	* 
	* You're a programmer, figure it out
	*/

	//sort_info._elapsed_timer.stop();
	

	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void _Template_::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // _TEMPLATE__H