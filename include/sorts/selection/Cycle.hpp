#ifndef CYCLE_HPP
#define CYCLE_HPP

#include "../../Sort.h"

/*
	Template Sort class

	Runs a ____ sort
*/
class Cycle : public Sort {
public:
	explicit Cycle();				// Default Constructor

	explicit Cycle(short length);	// Primary Constructor

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
Cycle::Cycle() : Sort() {
	sort_info._sort_name = "Selection Sorts: Cycle Sort";
}

// Primary Constructor
Cycle::Cycle(short length) : Sort(length) {
	sort_info._sort_name = "Selection Sorts: Cycle Sort";
}

// Runs the sort
void Cycle::run() {
	sort_info.init_labels();
	sort_info._n_swaps -= len;
	sort_info._n_main_writes -= len;

	while (!started) {}

	//sort_info._elapsed_timer.start();

    //int start, element, pos, temp, i;

    for (int start = 0; start <= len - 2; start++) {
        int elem = arr[start];

        int pos = start;

        for (int i = start + 1; i < len; i++) {

            ++sort_info._n_comparisons;
            if (arr[i] < elem) {
                ++pos;
            }
        }

        ++sort_info._n_comparisons;
        if (pos == start) {
            continue;
        }

        while (elem == arr[pos]) {
            ++pos;
        }

        ++sort_info._n_comparisons;
        if (pos != start) 
        {  
            swap(pos, start);
            usleep(delay);
        }

        while (pos != start)
        {
            pos = start;

            for (int i = start + 1; i < len; i++) {

                ++sort_info._n_comparisons;
                if (arr[i] < elem) {
                    ++pos;
                }
            }
                

            while (elem == arr[pos]) {
                ++pos;
            }

            ++sort_info._n_comparisons;
            if (elem != arr[pos])
            {
                // No clue as to why the swap method wasn't working
                // But this works so I'll take it

                int temp = elem;
                elem = arr[pos];
                arr[pos] = temp;
                ++sort_info._n_swaps;
                usleep(delay);
            }
        }
    }

	//sort_info._elapsed_timer.stop();


	usleep(1000);	// Little pause before the check

	check();	// Check

	finished = true;
}

void Cycle::check() {
	for (short i = 1; i < len; ++i) {
		swap_a = i - 1;
		swap_b = i;
		check_ind = i;

		usleep(delay);
	}

	swap_a = -1;
	swap_b = -1;
}

#endif // CYCLE_HPP