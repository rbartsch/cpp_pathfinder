#ifndef FINDPATH_HPP
#define FINDPATH_HPP

#include <queue>
#include <map>
#include <array>
#include "grid.hpp"


class FindPath {
private:
	int x;
	int y;

	Grid &grid_;
	std::queue<std::array<int, 2>> open_set;
	std::map<std::array<int, 2>, std::array<int, 2>> closed_set;

public:
	FindPath(int x, int y, Grid& grid);
	void search();
	std::vector<std::array<int, 2>> get_path(int x, int y);
	std::string get_path_layout_raw(std::vector<std::array<int, 2>> path);
	std::string get_path_layout_formatted(std::vector<std::array<int, 2>> path);
};

#endif // !FINDPATH_HPP