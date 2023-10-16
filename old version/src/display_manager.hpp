#ifndef DISPLAY_MANAGER_HPP
#define DISPLAY_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <thread>

#include "sorts.hpp"

class DisplayManager {
private:
	sf::RenderWindow window;
	sf::Font prog_font;

	std::vector<int> m_values;

	int width, height, delay;

	bool started = false;
	bool finished = false;

	float bar_width, bar_height;
	int n_values;

	void sort(int sorting_choice);
	void draw_values();

	void check(int n);
public:
	DisplayManager(int width, int height, int sps);

	void run(int sorting_choice, std::vector<int> values);
};

void DisplayManager::sort(int sorting_choice) {
	while (!started) {}
	while (started && !finished) {
		if (sorting_choice == 0) {
			insertion_sort(m_values, delay);
			finished = true;
		}
		else if (sorting_choice == 1) {
			selection_sort(m_values, delay);
			finished = true;
		}
		else if (sorting_choice == 2) {
			cocktail_sort(m_values, delay);
			finished = true;
		}
		else if (sorting_choice == 3) {
			gnome_sort(m_values, delay);
			finished = true;
		}
		else if (sorting_choice == 4) {
			bubble_sort(m_values, delay);
			finished = true;
		}
		else if (sorting_choice == 5) {
			quick_sort(m_values, delay, 0, n_values - 1);
			finished = true;
		}
		else if (sorting_choice == 6) {
			merge_sort(m_values, delay, 0, n_values - 1);
			finished = true;
		}
		else if (sorting_choice == 7) {
			bead_sort(m_values, delay);
			finished = true;
		}
		else if (sorting_choice == 8) {
			bogo_sort(m_values, delay);
			finished = true;
		}
		else if (sorting_choice == 9) {
			bitonic_sort(m_values, delay, 0, n_values, 1);
			finished = true;
		}
	}
}

void DisplayManager::draw_values() {
	window.clear(sf::Color::Black);

	sf::RectangleShape bar(sf::Vector2f(0, 0));
	for (int i = 0; i < n_values; ++i) {
		bar.setSize(sf::Vector2f(bar_width, bar_height * m_values[i]));
		bar.setPosition(i * bar_width, height - bar.getSize().y);
		// Red and white check
		if (i == g_index_a || i == g_index_b) {
			bar.setFillColor(sf::Color::Red);
		}
		else {
			bar.setFillColor(sf::Color::White);
		}

		window.draw(bar);
	}
}

// Lol this does nothing, its purely aesthetic
void DisplayManager::check(int n) {
	window.clear(sf::Color::Black);

	sf::RectangleShape bar(sf::Vector2f(0, 0));
	for (int i = 0; i < n_values; ++i) {
		bar.setSize(sf::Vector2f(bar_width, bar_height * m_values[i]));
		bar.setPosition(i * bar_width, height - bar.getSize().y);
		if (n > i) {
			bar.setFillColor(sf::Color::Green);
		}
		else {
			bar.setFillColor(sf::Color::White);
		}
		

		window.draw(bar);
	}
}

DisplayManager::DisplayManager(int width, int height, int delay) {
	this->width = width;
	this->height = height;
	this->delay = delay;

	if (!prog_font.loadFromFile("Arial.ttf")) {
		std::cout << "Error opening font...\n";
		return;
	}

	window.create(sf::VideoMode(width, height), "Sortin Algorithm Visualizer");
}

void DisplayManager::run(int sorting_choice, std::vector<int> values) {
	for (int i : values) { m_values.push_back(i); }

	n_values = values.size();
	bar_width = float(width) / float(n_values);
	bar_height = float(height) / float(n_values);

	sf::Text start_label("Press <Enter> to start", prog_font, 24);
	start_label.setFillColor(sf::Color::White);
	// Center start label
	sf::FloatRect start_bounds = start_label.getLocalBounds();
	start_label.setOrigin(start_bounds.left + start_bounds.width / 2.f, start_bounds.top + start_bounds.height / 2.f);
	start_label.setPosition(sf::Vector2f(width / 2.f, height / 2.f));

	std::thread sort_thread(&DisplayManager::sort, this, sorting_choice);

	int check_ind = 0;
	int check_inc = n_values / 500;
	if (check_inc == 0) { check_inc = 1; }

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed()) {
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				started = true;
			}
		}

		if (!started) {
			window.draw(start_label);
		}
		else {
			if (finished && sort_thread.joinable()) {
				sort_thread.join();
			}
			else {  // I hate this :D
				if (!finished) {
					draw_values();
				}
				if (finished && check_ind <= n_values) {
					check(check_ind += check_inc);
				}
				
			}
		}
		

		window.display();
	}
}

#endif
