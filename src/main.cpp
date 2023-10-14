#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <time.h>
#include <random>

#include "display_manager.hpp"



/*
	Get Input (inclusive)
	@param prompt
	@param min
	@param max
	@return choice
*/
int getInput(const std::string& prompt, int min, int max);

/*
	is Numeric
	@param str
	@return T/F if str is only numeric
*/
bool is_numeric(const std::string& str);



int main() {
	std::string sorting_prompt = "Choose an algorithm listed below:\n"
		" (0) Insertion\n"
		" (1) Selection\n"
		" (2) Cocktail\n"
		" (3) Gnome\n"
		" (4) Bubble\n"
		" (5) Quick\n"
		" (6) Merge\n"
		" (7) Bead/Gravity\n"
		" (8) Bogo\n"
		" (9) Bitonic Merge *Number of elements must be 2^(n)!*";

	int sorting_choice = getInput(sorting_prompt, 0, 9);
	system("CLS");
	int n_values = getInput("Enter the number of elements:", 2, -1);
	std::vector<int> values;
	for (int i = 0; i < n_values; ++i) { values.push_back(i + 1); }
	srand(time(NULL));
	for (int i = 0; i < n_values; ++i) {
		int rI = rand() % n_values;
		swap(values[i], values[rI]);
	}

	int width = 1920, height = 1080;
	system("CLS");
	int ms = getInput("Enter delay (us):", -1, -1);


	DisplayManager disp_man(width, height, ms);
	disp_man.run(sorting_choice, values);
}

int getInput(const std::string& prompt, int min, int max) {
	std::string choice_str;
	std::cout << prompt << "\n";
	std::cout << " > ";
	std::cin >> choice_str;
	while (!is_numeric(choice_str)) {
		std::cout << "Please input only numerical digits:\n > ";
		std::cin >> choice_str;
	}


	int choice = std::stoi(choice_str);
	while (((min < 0) ? false : choice < min)  || ((max < 0) ? false : choice > max)) {
		std::cout << "Please input a digit between " << ((min < 0) ? "-inf" : std::to_string(min)) << " & " << ((max < 0) ? "inf" : std::to_string(max)) << ":\n > ";
		std::cin >> choice;
	}

	return choice;
}

bool is_numeric(const std::string& str) {
	for (char c : str) {
		if (c < 48 || c > 57) { return false; }
	}
	return true;
}
