#include "../include/Sort_Information.h"

/**
* Yes I am aware that this code is extremely illedgible
*
* After consideration with some peers it's been concluded
* that having some shoddy low-level code that runs out of
* sight in the background is better than some shoddy 
* high-level code that is potentially more specialized.
* 
* Anywhere I could simplify with function calls, I have
*/

const int FONT_SIZE = 24;


// Default Constructor
SortInformation::SortInformation() {
	_sort_name = "NULL";
	_n_values = 0;
	_delay = 0;

	//_sort_time = 0;

	_n_comparisons = 0;
	_n_swaps = 0;
	_n_reversals = 0;

	_n_main_writes = 0;
	_n_aux_writes = 0;

	//_elapsed_timer = Timer();

	font.loadFromFile("././Arial.ttf");

	init_labels();
}


// Primary Constructor
SortInformation::SortInformation(std::string sort_name, short n_values, short delay) {
	_sort_name = sort_name;
	_n_values = n_values;
	_delay = delay;

	//_sort_time = 0;

	_n_comparisons = 0;
	_n_swaps = 0;
	_n_reversals = 0;

	_n_main_writes = 0;
	_n_aux_writes = 0;

	//_elapsed_timer = Timer();

	font.loadFromFile("././Arial.ttf");

	init_labels();
}


// Helper function to initialize the labels
void SortInformation::init_labels() {
	std::string sort_label_str = 
		_sort_name + "\n" + 
		std::to_string(_n_values) + 
		" Elements";

	std::string time_label_str =
		"Delay:" + format_to_string(_delay) + "ms";
		//"\nVisual Time: " + elapsed_string() + 
		//"\nSort Time: ~" + format_to_string(_sort_time) + "ms";

	std::string operation_label_str = 
		std::to_string(_n_comparisons) + " Comparisons\n" + 
		std::to_string(_n_swaps) + " Swaps\n" + 
		std::to_string(_n_reversals) + " Reversals\n";

	std::string write_label_str =
		std::to_string(_n_main_writes) + " Writes to main array\n" +
		std::to_string(_n_aux_writes) + " Writes to axiliary array(s)";

	// Sort info label creation
	_sort_label.setString(sort_label_str);
	_sort_label.setFillColor(sf::Color::White);
	_sort_label.setFont(font);
	_sort_label.setCharacterSize(FONT_SIZE);
	_sort_label.setPosition(0, 0);

	// Time info label creation
	_time_label.setString(time_label_str);
	_time_label.setFillColor(sf::Color::White);
	_time_label.setFont(font);
	_time_label.setCharacterSize(FONT_SIZE);
	_time_label.setPosition(0, 60);

	// Operation info label creation
	_operation_label.setString(operation_label_str);
	_operation_label.setFillColor(sf::Color::White);
	_operation_label.setFont(font);
	_operation_label.setCharacterSize(FONT_SIZE);
	_operation_label.setPosition(0, 100);

	// Write info label creation
	_write_label.setString(write_label_str);
	_write_label.setFillColor(sf::Color::White);
	_write_label.setFont(font);
	_write_label.setCharacterSize(FONT_SIZE);
	_write_label.setPosition(0, 200);
}


// Updates the non-constant labels
void SortInformation::update_labels() {
	//_sort_time = _elapsed_timer.getElapsed();

	std::string time_label_str =
		"Delay:" + format_to_string(_delay) + "ms";
		//"\nVisual Time: " + elapsed_string() +
		//"\nSort Time: ~" + format_to_string(_sort_time) + "ms";

	std::string operation_label_str =
		std::to_string(_n_comparisons) + " Comparisons\n" +
		std::to_string(_n_swaps) + " Swaps\n" +
		std::to_string(_n_reversals) + " Reversals\n";

	std::string write_label_str =
		std::to_string(_n_main_writes) + " Writes to main array\n" +
		std::to_string(_n_aux_writes) + " Writes to axiliary array(s)";

	_time_label.setString(time_label_str);
	_operation_label.setString(operation_label_str);
	_write_label.setString(write_label_str);
}


// Returns a reference to the _sort_label object
sf::Text& SortInformation::getSortLabel() {
	return _sort_label;
}


// Returns a reference to the _time_label object
sf::Text& SortInformation::getTimeLabel() {
	return _time_label;
}


// Returns a reference to the _operation_label object
sf::Text& SortInformation::getOperationLabel() {
	return _operation_label;
}


// Returns a reference to the _write_label object{
sf::Text& SortInformation::getWriteLabel() {
	return _write_label;
}


// Formats the given integer representing time in us
std::string SortInformation::format_to_string(long long n) {
	float f_micro = n;
	float f_milli = f_micro / 1000.f;

	std::ostringstream result;
	result << std::fixed << std::setprecision(3) << std::to_string(f_milli);
	
	return std::move(result).str();
}


// Formats the current elapsed time as a string
/*
std::string SortInformation::elapsed_string() {
	// 1 seconds = 1000 ms and 1 ms = 1000us
	int seconds = _elapsed_timer.getElapsed() / 1000000; 
	div_t min_and_sec = div(seconds, 60);

	std::ostringstream result;
	result << std::to_string(min_and_sec.quot) << ":" <<
		std::setw(2) << std::setfill('0') <<
		std::to_string(min_and_sec.rem);
	
	return std::move(result).str();
}
*/