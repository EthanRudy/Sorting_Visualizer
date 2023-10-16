#include "../include/Timer.h"

// Default Constructor
Timer::Timer() {
	running = false;
}

// Starts the timer
void Timer::start() {
	s_time = std::chrono::high_resolution_clock::now();
}

// Stops the timer
void Timer::stop() {
	e_time = std::chrono::high_resolution_clock::now();
	running = false;
}

// Gets the elapsed time (in microseconds)
long long Timer::getElapsed() {
	if (running) {
		e_time = std::chrono::high_resolution_clock::now();
	}
	return std::chrono::duration_cast<std::chrono::microseconds>(e_time - s_time).count();
}