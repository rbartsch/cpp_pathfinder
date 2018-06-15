#include "grid.hpp"

/*
Create 2D grid with given width and height
*/
Grid::Grid(int w, int h) {
	width = w;
	height = h;
	layout.resize(w, std::vector<int>(h, 0));
	symbols = { ".", "#" };
	blockers = { 1 };
}


/*
Get the tile at given coordinates
*/
int Grid::get_tile(int x, int y) {
	if ((x < 0 || y < 0) || (x > width - 1 || y > height - 1)) {
		return -1;
	}
	else {
		return layout[x][y];
	}
}


/*
Set the tile's value at given coordinates
*/
bool Grid::set_tile(int x, int y, int v) {
	if ((x < 0 || y < 0) || (x > width - 1 || y > height - 1)) {
		return false;
	}
	else {
		layout[x][y] = v;
		return true;
	}
}


/*
Gets coordinates of the four directional neighbours only, no diagonals.
Returns -1 if neighbour is out of bounds or if the origin is out of bounds
*/
std::vector<std::array<int, 2>> Grid::get_neighbours(int x, int y) {
	std::vector<std::array<int, 2>> neighbours;
	neighbours.assign(4, std::array<int, 2> {-1, -1});

	if ((x < 0 || y < 0) || (x > width - 1 || y > height - 1)) {
		return neighbours;
	}
	else {
		if (y - 1 >= 0) {
			neighbours[0] = { x, y - 1 };
		}

		if (x + 1 <= width - 1) {
			neighbours[1] = { x + 1, y };
		}

		if (y + 1 <= height - 1) {
			neighbours[2] = { x, y + 1 };
		}

		if (x - 1 >= 0) {
			neighbours[3] = { x - 1, y };
		}
	}

	return neighbours;
}


/*
Gets a copy of the grid values
*/
std::vector<std::vector<int>> Grid::get_copy_of_layout_values()
{
	std::vector<std::vector<int>> copied_layout;
	copied_layout = layout;
	return copied_layout;
}


/*
Gets a grid layout of the numerical tile values
*/
std::string Grid::get_layout_raw() {
	std::string s = "";

	// TODO(rbartsch): Use iterators instead
	for (int y = 0; y <= height - 1; y++) {
		for (int x = 0; x <= width - 1; x++) {
			s += std::to_string(layout[x][y]);
		}

		if (y != height - 1) {
			s += "\n";
		}
	}

	return s;
}


/*
Gets a grid layout of the symbols mapped to the numerical tile values
*/
std::string Grid::get_layout_formatted() {
	std::string s = "";

	// TODO(rbartsch): Use iterators instead
	for (int y = 0; y <= height - 1; y++) {
		for (int x = 0; x <= width - 1; x++) {
			if (layout[x][y] >= 0 && layout[x][y] <= symbols.size() - 1) {
				s += symbols[layout[x][y]];
			}
			else {
				s += "?";
			}
		}

		if (y != height - 1) {
			s += "\n";
		}
	}

	return s;
}