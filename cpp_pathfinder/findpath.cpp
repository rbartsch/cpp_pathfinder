/* 
My implementation of the Breadth-first search algorithm.
Ref: https://en.wikipedia.org/wiki/Breadth-first_search
*/

#include <algorithm>
#include <iostream>
#include "findpath.hpp"

FindPath::FindPath(int x, int y, Grid& grid) : grid_(grid) {
	this->x = x;
	this->y = y;

	open_set.push({ x, y });
}


void FindPath::search() {
	while (!open_set.empty()) {
		std::array<int, 2> current = open_set.front();
		open_set.pop();

		std::vector<std::array<int, 2>> next = grid_.get_neighbours(current[0], current[1]);

		// determine blockers
		for (int i = 0; i < next.size(); i++) {
			std::array<int, 2> coords = next[i];
			int tile_value = grid_.get_tile(coords[0], coords[1]);
			for (int j = 0; j < grid_.blockers.size(); j++) {
				if (tile_value == grid_.blockers[j]) {
					next[i] = { -1, -1 };
				}
			}
		}

		for (int i = 0; i < next.size(); i++) {
			std::array<int, 2> coords = next[i];
			// ignore tiles that were identified as blockers
			if (coords[0] >= 0 && coords[1] >= 0) {
				std::map<std::array<int, 2>, std::array<int, 2>>::iterator it;
				it = closed_set.find(coords);
				if (it == closed_set.end()) {
					open_set.push({ coords[0], coords[1] });
					closed_set[coords] = current;
				}
			}
		}
	}
}


std::vector<std::array<int, 2>> FindPath::get_path(int x, int y) {
	std::vector<std::array<int, 2>> path;

	std::array<int, 2> current = { x, y };
	std::array<int, 2> start = { this->x, this->y };
	while (current != start) {
		path.push_back(current);

		std::map<std::array<int, 2>, std::array<int, 2>>::iterator it;
		it = closed_set.find(current);
		if (it != closed_set.end()) {
			current = closed_set[it->first];
		}
	}

	// Include start position in path
	//path.push_back(start);
	std::reverse(path.begin(), path.end());

	//for (int i = 0; i < path.size(); i++) {
	//	std::cout << path[i][0] << "," << path[i][1] << std::endl;
	//}

	return path;
}


std::string FindPath::get_path_layout_raw(std::vector<std::array<int,2>> path) {
	std::string s = "";

	// TODO(rbartsch): Use iterators instead
	for (int y = 0; y <= grid_.height - 1; y++) {
		for (int x = 0; x <= grid_.width - 1; x++) {
			if (std::find(path.begin(), path.end(), std::array<int, 2>{ x, y }) != path.end()) {
				s += std::to_string(2);
			}
			else {
				s += std::to_string(grid_.layout[x][y]);
			}
		}

		if (y != grid_.width - 1) {
			s += "\n";
		}
	}

	return s;
}


std::string FindPath::get_path_layout_formatted(std::vector<std::array<int, 2>> path) {
	std::string s = "";

	// TODO(rbartsch): Use iterators instead
	for (int y = 0; y <= grid_.height - 1; y++) {
		for (int x = 0; x <= grid_.width - 1; x++) {
			if (std::find(path.begin(), path.end(), std::array<int, 2>{ x, y }) != path.end()) {
				s += "*";
			}
			else {
				s += grid_.symbols[grid_.layout[x][y]];
			}
		}

		if (y != grid_.width - 1) {
			s += "\n";
		}
	}

	return s;
}