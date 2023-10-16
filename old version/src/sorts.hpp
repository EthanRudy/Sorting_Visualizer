#ifndef SWAPS_HPP
#define SWAPS_MANAGER_HPP

#include <windows.h>
#include <chrono>
#include <thread>

int g_index_a, g_index_b;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void insertion_sort(std::vector<int>& values, int delay) {
	for (int i = 1; i < values.size(); ++i) {
		for (int j = i; j > 0 && values[j - 1] > values[j]; --j) {
			swap(values[j], values[j - 1]);
			g_index_a = j, g_index_b = (j - 1);
			std::this_thread::sleep_for(std::chrono::microseconds(delay));
		}
	}

	g_index_a = -1, g_index_b =  -1;
}

void selection_sort(std::vector<int>& values, int delay) {
	int n_values = values.size();
	int i, k;

	for (i = 0; i < n_values - 1; ++i) {
		k = i;
		for (int j = i + 1; j < n_values; ++j) {
			if (values[i] > values[j]) {
				swap(values[i], values[j]);
				g_index_a = i, g_index_b = j;
				std::this_thread::sleep_for(std::chrono::microseconds(delay));
			}
		}
	}

	if (k != i) {
		swap(values[i], values[k]);
		g_index_a = i, g_index_b = k;
		std::this_thread::sleep_for(std::chrono::microseconds(delay));
	}

	g_index_a = -1, g_index_b = -1;
}

void cocktail_sort(std::vector<int>& values, int delay) {
	bool swapped;
	do {
		swapped = false;

		for (int i = 0; i < values.size() - 1; ++i) {
			if (values[i] > values[i + 1]) {
				swap(values[i], values[i + 1]);
				swapped = true;
				g_index_a = i, g_index_b = i + 1;
				std::this_thread::sleep_for(std::chrono::microseconds(delay));
			}
		}

		if (!swapped) { break; }

		for (int i = values.size() - 2; i > -1; --i) {
			if (values[i] > values[i + 1]) {
				swap(values[i], values[i + 1]);
				swapped = true;
				g_index_a = i, g_index_b = i + 1;
				std::this_thread::sleep_for(std::chrono::microseconds(delay));
			}
		}

	} while (swapped);
}

void gnome_sort(std::vector<int>& values, int delay) {
	for (int pos = 0; pos < values.size();) {
		if (pos == 0 || values[pos] >= values[pos - 1]) {
			++pos;
		}
		else {
			swap(values[pos], values[pos - 1]);
			g_index_a = pos, g_index_b = pos - 1;
			std::this_thread::sleep_for(std::chrono::microseconds(delay));
			--pos;
		}
	}
}

void bubble_sort(std::vector<int>& values, int delay) {
	int n_values = values.size();
	
	bool swapped;
	for (int i = 0; i < n_values - 1; ++i) {
		swapped = false;
		for (int j = 0; j < n_values - i - 1; ++j) {
			if (values[j] > values[j + 1]) {
				swap(values[j], values[j + 1]);
				swapped = true;
				g_index_a = j, g_index_b = j + 1;
				std::this_thread::sleep_for(std::chrono::microseconds(delay));
			}
		}
		if (!swapped) { break; }
	}
}



int quick_part(std::vector<int>& values, int delay, int l, int h) {
	int p = values[h];
	int i = l - 1;

	for (int j = l; j < h; ++j) {
		if (values[j] <= p) {
			++i;
			swap(values[i], values[j]);
			g_index_a = i, g_index_b = j;
			std::this_thread::sleep_for(std::chrono::microseconds(delay));
		}
	}
	++i;
	swap(values[i], values[h]);
	g_index_a = i, g_index_b = h;
	std::this_thread::sleep_for(std::chrono::microseconds(delay));

	return i;
}

void quick_sort(std::vector<int>& values, int delay, int l, int h) {
	if (l < h) {
		int p = quick_part(values, delay, l, h);
		std::this_thread::sleep_for(std::chrono::microseconds(delay));

		quick_sort(values, delay, l, p - 1);
		quick_sort(values, delay, p + 1, h);
	}
}


void merge(std::vector<int>& values, int delay, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	std::vector<int> L(n1);
	for (int i = 0; i < n1; ++i) { L[i] = values[p + i]; }
	std::vector<int> M(n2);
	for (int j = 0; j < n2; ++j) { M[j] = values[q + j + 1]; }

	int i = 0, j = 0, k = p;

	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			values[k] = L[i];
			g_index_a = k, g_index_b = k;
			std::this_thread::sleep_for(std::chrono::microseconds(delay));
			++i;
		}
		else {
			values[k] = M[j];
			g_index_a = k, g_index_b = k;
			std::this_thread::sleep_for(std::chrono::microseconds(delay));
			++j;
		}
		++k;
	}

	while (i < n1) {
		values[k] = L[i];
		g_index_a = k, g_index_b = k;
		std::this_thread::sleep_for(std::chrono::microseconds(delay));
		++i;
		++k;
	}

	while (j < n2) {
		values[k] = M[j];
		g_index_a = k, g_index_b = k;
		std::this_thread::sleep_for(std::chrono::microseconds(delay));
		++j;
		++k;
	}
}

void merge_sort(std::vector<int>& values, int delay, int begin, int end) {
	if (begin < end) {
		int mid = begin + (end - begin) / 2;
		merge_sort(values, delay, begin, mid);
		merge_sort(values, delay, mid + 1, end);
		merge(values, delay, begin, mid, end);
	}
}


void bead_sort(std::vector<int>& values, int delay) {
	int max = values[0];
	int n_values = values.size();

	for (int i = 1; i < n_values; ++i) {
		if (values[i] > max) {
			max = values[i];
		}
	}

	std::vector<std::vector<int>> beads;
	beads.resize(n_values);

	for (int i = 0; i < n_values; ++i) {
		for (int j = 0; j < values[i]; ++j) {
			beads[i].resize(max);
			std::fill(beads[i].begin(), beads[i].end(), 0);
		}
	}

	for (int i = 0; i < n_values; ++i) {
		for (int j = 0; j < values[i]; ++j) {
			beads[i][j] = 1;
		}
	}

	for (int j = 0; j < max; ++j) {
		int sum = 0;
		for (int i = 0; i < n_values; ++i) {
			sum += beads[i][j];
			beads[i][j] = 0;
		}
		for (int i = n_values - 1; i >= n_values - sum; --i) {
			beads[i][j] = 1;
		}
	}

	for (int i = 0; i < n_values; ++i) {
		int sum = 0;
		for (int j = 0; j < max; ++j) {
			sum += beads[i][j];
		}
		values[i] = sum;
		g_index_a = i, g_index_b = i;
		std::this_thread::sleep_for(std::chrono::microseconds(delay));
	}
}


void bogo_sort(std::vector<int>& values, int delay) {
	int n_values = values.size();
	bool sorted = false;

	while (!sorted) {
		for (int i = 0; i < n_values; ++i) {
			int rI = rand() % n_values;
			swap(values[i], values[rI]);
			g_index_a = i, g_index_b = rI;
			std::this_thread::sleep_for(std::chrono::microseconds(delay));
		}

		sorted = true;

		for (int i = 1; i < n_values; ++i) {
			if (values[i] < values[i - 1]) {
				sorted = false;
				break;
			}
		}
	}
	
}

void compSwap(std::vector<int>& values, int delay, int i, int j, int dir) {
	if (dir == (values[i] > values[j])) {
		swap(values[i], values[j]);
		g_index_a = i, g_index_b = j;
		std::this_thread::sleep_for(std::chrono::microseconds(delay));
	}
}

void bitonic_merge(std::vector<int>& values, int delay, int low, int cnt, int dir) {
	if (cnt > 1) {
		int k = cnt / 2;
		for (int i = low; i < low + k; ++i) {
			compSwap(values, delay, i, i + k, dir);
		}
		bitonic_merge(values, delay, low, k, dir);
		bitonic_merge(values, delay, low + k, k, dir);
	}
}

void bitonic_sort(std::vector<int>& values, int delay, int low, int cnt, int dir) {
	if (cnt > 1) {
		int k = cnt / 2;
		bitonic_sort(values, delay, low, k, 1);
		bitonic_sort(values, delay, low + k, k, 0);
		bitonic_merge(values, delay, low, cnt, dir);
	}
}

#endif
