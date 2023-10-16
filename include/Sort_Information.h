#ifndef SORT_INFORMATION_H
#define SORT_INFORMATION_H

#include <chrono>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>


#include "Timer.h"

class SortInformation {
public:
	explicit SortInformation();			// Default Constructor

	explicit SortInformation(std::string sort_name, short n_values, short delay);		// Primary Constructor

	// Constants (won't update)
	std::string _sort_name;		// Category and name of sort
	short _n_values;			// Number of values in sort array
	int _delay;				// Delay per operation

	int _n_comparisons;			// Running total of comparisons
	int _n_swaps;				// Running total of swaps
	int _n_reversals;			// Running total of reversals

	int _n_main_writes;			// Running total of writes to main array
	int _n_aux_writes;			// Running total of writes to axiliary arrays
	// Yes I had to look up how to spell "axiliary" :3

	/**
	* Helper function to initialize the labels
	*/
	void init_labels();

	/**
	* Updates the non-constant labels
	* Called every frame
	*/
	void update_labels();
	
	/**
	* Returns a reference to the _sort_label object
	* @return st::Text&
	*/
	sf::Text& getSortLabel();

	/**
	* Returns a reference to the _time_label object
	* @return st::Text&
	*/
	sf::Text& getTimeLabel();

	/**
	* Returns a reference to the _operation_label object
	* @return st::Text&
	*/
	sf::Text& getOperationLabel();

	/**
	* Returns a reference to the _write_label object
	* @return st::Text&
	*/
	sf::Text& getWriteLabel();

	// Time object(s)
	// Timer _elapsed_timer;
protected:

private:
	// Text Object(s)
	sf::Font font;
	sf::Text _sort_label;		// Unchanging label that holds name and n_values
	sf::Text _time_label;		// Label holding time data
	sf::Text _operation_label;	// Label holding operational data
	sf::Text _write_label;		// Label holding write data

	/**
	* Formats the given integer representing time in us
	* to the form X.XXX in ms
	*/
	std::string format_to_string(long long n);

	/**
	* Formats the current elapsed time as a string 
	* in the form X:XX
	*/
	// UNUSED
	//std::string elapsed_string();
};

#endif // SORT_INFORMATION_H