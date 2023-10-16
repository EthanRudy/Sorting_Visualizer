#include "../include/Visualizer.h"

// Primary Constructor
Visualizer::Visualizer(Sort* sort) {
	_font.loadFromFile("././Arial.ttf");

	_sort = sort;

	_w_win = 1920;
	_h_win = 1080;

	// Not stressed about only 2 getLength()'s
	_w_bar = _w_win / _sort->getLength();
	_h_bar = _h_win / _sort->getLength();

	_started = false;
}

// Initializes the window object
void Visualizer::init_window() {
	_window.create(sf::VideoMode(_w_win, _h_win), "Sorting Algorithm Visualizer");
	//_window.setFramerateLimit(165);
	
	// Setup label visuals
	_start_stop_label.setString("Press <Enter> to start");
	_start_stop_label.setFillColor(sf::Color::White);
	_start_stop_label.setFont(_font);
	_start_stop_label.setCharacterSize(24);

	// Center the label
	sf::FloatRect label_bounds = _start_stop_label.getLocalBounds();
	_start_stop_label.setOrigin(label_bounds.left + label_bounds.width / 2.0f,
		label_bounds.top + label_bounds.height / 2.0f);
	_start_stop_label.setPosition(sf::Vector2f(_w_win / 2.f, _h_win / 2.f));

	// Maybe load some extra settings like framerate or something
	// Something slay for sure
	_window.setFramerateLimit(60);
}

// Starts up the visualizer
void Visualizer::run() {
	// Start sorting thread
	_sort_thread = std::thread(&Sort::run, _sort);

	// Main thread loop
	while (_window.isOpen()) {
		poll_events();	// Check events

		// Display the starting label
		if (!_started) {
			_window.draw(_start_stop_label);
		}
		else {
			if (_sort->finished && _sort_thread.joinable()) {
				_sort_thread.join();
			}
			draw_sort();
			if (_sort->finished) {
				_window.draw(_start_stop_label);
			}
		}
		_window.display();
	}
}

// Manages events for the window object
void Visualizer::poll_events() {
	sf::Event e;

	while (_window.pollEvent(e)) {
		if (e.type == sf::Event::Closed()) {
			// Somehow close any open threads
			if (_sort_thread.joinable()) {
				_sort_thread.join();
			}
			_window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (!_started) {
				// TODO MOVE THIS
				_sort->shuffle();

				_started = true;
				_sort->started = true;

				/**
				* Don't confuse these two
				* _started is managing the visuals of the window and the start label
				* _sort->start is managing the second thread
				*/

				// Swapping to the close label
				_start_stop_label.setString("Press <Enter> to close");
				_start_stop_label.setPosition(sf::Vector2f(_w_win / 2.f, 12));
			}
			if (_sort->finished) {
				_window.close();
			}
		}
	}
}

// Draws the bar
void Visualizer::draw_sort() {
	_sort->sort_info.update_labels();

	_window.clear(sf::Color::Black);

	_window.draw(_sort->sort_info.getSortLabel());
	_window.draw(_sort->sort_info.getTimeLabel());
	_window.draw(_sort->sort_info.getOperationLabel());
	_window.draw(_sort->sort_info.getWriteLabel());

	short n_values = _sort->getLength();

	for (short i = 0; i < n_values; ++i) {
		// Size calculation
		_bar.setSize(sf::Vector2f(_w_bar, _h_bar * _sort->get(i)));
		// Position calculation
		_bar.setPosition(i * _w_bar, _h_win - (_h_bar * _sort->get(i)));
		
		// Color check
		if (i <= _sort->check_ind) {
			_bar.setFillColor(sf::Color::Green);
			// Yes I'll optimize this later but its been 8 hours
			if (i == _sort->swap_a || i == _sort->swap_b) {
				_bar.setFillColor(sf::Color::Red);
			}
		} else if (i == _sort->swap_a || i == _sort->swap_b) {
			_bar.setFillColor(sf::Color::Red);
		}
		else {
			_bar.setFillColor(sf::Color::White);
		}

		_window.draw(_bar);
	}
}