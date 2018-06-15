#include <iostream>
#include "grid.hpp"
#include "findpath.hpp"

int main() {
	Grid grid = Grid::Grid(3,3);

	grid.set_tile(0, 0, 0);
	grid.set_tile(1, 0, 1);
	grid.set_tile(2, 0, 0);
	grid.set_tile(0, 1, 0);
	grid.set_tile(1, 1, 0);
	grid.set_tile(2, 1, 0);
	grid.set_tile(0, 2, 0);
	grid.set_tile(1, 2, 1);
	grid.set_tile(2, 2, 0);

	std::cout << "Grid layout raw (0 passable; 1 blocker):\n" << grid.get_layout_raw() << "\n" << std::endl;
	std::cout << "Grid layout formatted (. passable; # blocker):\n" << grid.get_layout_formatted() << "\n" << std::endl;

	FindPath fp = FindPath::FindPath(0, 0, grid);
	fp.search();
	std::vector<std::array<int,2>> path = fp.get_path(2, 2);

	std::cout << "Grid layout raw indicating path (2):\n" << fp.get_path_layout_raw(path) << "\n" << std::endl;
	std::cout << "Grid layout formatted indicating path (*):\n" << fp.get_path_layout_formatted(path) << "\n" << std::endl;

	std::cout << "\nType q to quit: ";
	while (std::cin.get() != 'q') {}
}