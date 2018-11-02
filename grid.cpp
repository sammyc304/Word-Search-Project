//
//  grid.cpp
//  EECE2560 3b
//
//

#include "grid.hpp"

/*constructor for grid class takes a string as a parameter. This string corresponds to a file name, and the program decides the file to import and grid size based off this. It then navigates through the word search and converts it into a matrix of characters*/
Grid::Grid(string grid)
{
	if (grid == "input15.txt") //The values seen here are specific for Project 3A, but could be modified to set grid_size to just the size of the inputted matrix
	{
		grid_size = 15;
	}
	else if (grid == "input30.txt")
	{
		grid_size = 30;
	}
	else if (grid == "input6.txt")
	{
		grid_size = 6;
	}
	else
	{
		grid_size = 50;
	}
	letters.resize(grid_size, grid_size);
	ifstream inFile; // input file 
	inFile.open(grid);
	if (!inFile) // checks if file cannot open 
	{
		cout << "Cannot open file" << endl;
		exit(0);
	}
	for (int i = 0; i < grid_size; i++) // rows of word search
	{
		for (int j = 0; j < grid_size; j++) // columns of word search
		{
			inFile >> letters[i][j];
		} // end for
	} // end for
	inFile.close();
} // end constructor

/* returns size of grid*/
int Grid::get_size()
{
	return grid_size;
} // end grid_size

char Grid::get_char(int x, int y)
{
	return letters[x][y];
}


/* The print function prints the grid in such a way to look exactly like the word search*/
void Grid::print()
{
	for (int i = 0; i < grid_size; i++) // rows
	{
		for (int j = 0; j < grid_size; j++) // columns
		{
			cout << letters[i][j] << " "; // prints current character
		} // end for
		cout << "\n"; // skips line
	} // end for
} // end print()