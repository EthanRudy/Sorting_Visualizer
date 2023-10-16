#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics.hpp>

#include "Sort.h"

class Visualizer {
public:
	// Primary Constructor
	explicit Visualizer(Sort* sort);

	/**
	* Initializes the window object
	*/
	void init_window();

	/**
	* Starts up the visualizer
	*/
	void run();

	/**
	* Manages events for the window object
	*/
	void poll_events();

	/**
	* Draws the bar
	*/
	void draw_sort();
protected:
private:
	sf::RenderWindow _window;	// Window objects
	sf::Font _font;				// Font
	sf::Text _start_stop_label;	// Label for starting and stopping the visualizer

	sf::RectangleShape _bar;		// Bar object
	/**
	* I'm using only one bar to try and improve
	* the draw loop speeds
	*/

	float _w_win;		// Window width
	float _h_win;		// Window height

	float _w_bar;		// Bar width
	float _h_bar;		// Bar height

	Sort* _sort;		// Sorting algorithm pointer

	bool _started;		// Flag for when to start the sort

	std::thread _sort_thread;
};

#endif