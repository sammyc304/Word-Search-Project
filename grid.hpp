//
//  grid.hpp
//  EECE2560 3b
//
//
/* This is the header file for the grid class*/

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>
#include "matrix.hpp"
#include "dictionary.hpp"


class Grid
{
	matrix<char> letters;
	int grid_size;

public:
	Grid(string grid);
	int get_size();
	char get_char(int x, int y);
	void print();
};

#endif /* grid_hpp */