/*
	COPYRIGHT
*/

#include "../include/Sort.h"

// Default Constructor
Sort::Sort() {
	len = 0;
	arr = nullptr;

	swap_a = -1;
	swap_b = -1;

	delay = 0;

	started = false;
	finished = false;

	check_ind = -1;
}


// Primary Constructor
Sort::Sort(short length) {
	len = length;
	arr = new short[len];

	swap_a = -1;
	swap_b = -1;

	delay = 0;

	started = false;
	finished = false;

	check_ind = -1;

	// Fill default values
	for (short i = 0; i < len; ++i) { 
		arr[i] = i + 1; 
	}
}

// Deconstructor
Sort::~Sort() {
	delete[] arr;
}


// Randomly shuffles the array
void Sort::shuffle() {
	srand(time(0)); 

	for (short i = 0; i < len; ++i) {	// Shuffle
		short rand_i = rand() % len;
		swap(i, rand_i);
	}
}


// Set Delay
void Sort::setDelay(int delay) {
	this->delay = delay;

	sort_info._delay = delay;
}


// Set Length
void Sort::setLength(short length) {
	if (arr != nullptr) { delete[] arr; }
	len = length;
	arr = new short[len];

	for (short i = 0; i < len; ++i) { 
		arr[i] = i + 1; 
	}

	sort_info._n_values = len;
}


// Get Length
short Sort::getLength() {
	return len;
}

// Get Element
short Sort::get(short index) {
	return arr[index];
}

// Prints values to the console
void Sort::printArr() const {
	std::cout << "{ ";
	for (short i = 0; i < len - 1; ++i) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[len - 1] << " }\n";
}

// Runs the sort
void Sort::run() {
	finished = true;
}

// Checks the sort
void Sort::check() {

}

// Reverses all indices
void Sort::reverse() {
	++sort_info._n_reversals;

	for (int i = 0; i < len / 2; ++i) {
		swap(i, len - i - 1);
		usleep(delay);
	}
}

// Swaps two array indices (A & B)
void Sort::swap(short a, short b) {
	short temp = arr[a];		// Swap values
	arr[a] = arr[b];
	arr[b] = temp;

	swap_a = a;			// Set swap indices
	swap_b = b;

	++sort_info._n_swaps;
	++sort_info._n_main_writes;
}

// Replacement for not having unix function
void Sort::usleep(__int64 usec) {
	HANDLE timer;
	LARGE_INTEGER ft;

	ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time

	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}