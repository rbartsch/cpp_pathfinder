#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <string>
#include <array>

/*
Simple and extensible 2D grid for games or other representations
*/
class Grid {
public:
	std::vector<std::vector<int>> layout;
	std::vector<std::string> symbols;
	int width;
	int height;

	Grid(int w, int h);

	int get_tile(int x, int y);
	bool set_tile(int x, int y, int v);
	std::vector<std::array<int, 2>> get_neighbours(int x, int y);
	std::vector<std::vector<int>> get_copy_of_layout_values();
	std::string get_layout_raw();
	std::string get_layout_formatted();
	std::array<int, 1> blockers;
};

#endif // !GRID_HPP