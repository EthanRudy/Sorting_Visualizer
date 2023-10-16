#ifndef TIMER_H
#define TIMER_H

#include <chrono>

/**
* Concise timer class used mostly for readability purposes
*/
class Timer {
public:
	Timer();		// Default Constructor

	/**
	* Starts the timer
	*/
	void start();

	/**
	* Stops the timer
	*/
	void stop();

	/**
	* Gets the elapsed time (in microseconds)
	* Timer does NOT need to be stopped
	*/
	long long getElapsed();
protected:

private:
	std::chrono::high_resolution_clock::time_point s_time;	// Starting point
	std::chrono::high_resolution_clock::time_point e_time;
	bool running;	// Flag for checking if the timer is running
};

#endif // TIMER_H