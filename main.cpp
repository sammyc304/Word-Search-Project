//
//  main.cpp
//  EECE2560 3b
//
//

#include <iostream>
#include "dictionary.hpp"
#include "grid.hpp"

/*Directional_get locates all of the characters in a single direction with a starting place on the grid (a,b) and stores them in a character vector. This function takes an operation (1-8, for each direction), a starting location (a,b) and a grid object. Based on the operation, offsets 1 and 2 are set to increment in a specific direction. In each iteration, a new letter is acquired from the grid and stored in the character vector ‘word’. Once the starting place is reached again, word is returned.*/

vector<char> Directional_get(Grid g, int op, int a, int b)
{
	vector<char> word; // this vector contains all possible words found while navigating 
	int offset1 = 0, offset2 = 0; // offset 1 corresponds to the y direction, offset 2 corresponds to the x direction
	switch (op) // op is a parameter of the function that indicates the direction to search
	{
	case 1: offset1 = 1;
		break;
	case 2: offset1 = -1;
		break;
	case 3: offset2 = 1;
		break;
	case 4: offset2 = -1;
		break;
	case 5: offset1 = 1; offset2 = 1;
		break;
	case 6: offset1 = 1; offset2 = -1;
		break;
	case 7: offset1 = -1; offset2 = 1;
		break;
	case 8: offset1 = -1; offset2 = -1;
		break;
	} // end switch case
	int x = a;
	int y = b;

	do
	{
		word.push_back(g.get_char(x, y));
		x = x + offset1;
		y = y + offset2;
		// the following four if statements are necessary to catch the instance while navigating the word search when we hit a wall of the search

		if (x == g.get_size())  // if the x value exceeds the last letter on the right
		{
			x = 0;
		}

		if (y == g.get_size()) // if y value exceeds bottom letter
		{
			y = 0;
		}

		if (x == -1) // if the x value exceeds the last letter on the left
		{
			x = g.get_size() - 1;
		}

		if (y == -1) // if y value exceeds top letter
		{
			y = g.get_size() - 1;
		}

	} while (x != a || y != b); // this is the terminating condition, reached when we return to the starting letter
	return word;
} // end Directional_get

/*convertChar_String takes a character vector and passes a string vector by reference. Starting at a length of 5, strings are created by concatenating the elements(char) of the vector. These strings are then stored in the string vector ‘candidates’*/

void convertChar_String(vector<char> word, vector<string>& candidates)
{
	size_t x = 5; // size_t is effectively an integer, used for navigating a vector

	while (x <= word.size())
	{
		string strC(word.begin(), word.end() - (word.size() - x)); // converts the array of characters to a string
		candidates.push_back(strC); // adds to end of vector
		x++;
	} // end while
} // end convertChar_String

/*Generate_Candidates takes a grid object as a parameter and returns a string vector. Starting at location (0,0), Directional_get and convertChar_String are called 8 times(for each direction). Then the location gets incremented.*/

vector<string> Generate_Candidates(Grid g)
{
	vector<string> all_candidates; // This vector will contain all possible words 
	int size = g.get_size();
	for (int i = 0; i < size; i++)  // corresponds to the row number
	{
		int j = 0;
		for (j = 0; j < size; j++)  // corresponds to column number
		{
			int k = 1;
			for (k = 1; k <= 8; k++) // corresponds to each direction of a possible word
			{
				vector<char> word = Directional_get(g, k, i, j);
				convertChar_String(word, all_candidates);
			} // end for
		} // end for
	} //end for
	return all_candidates;
} //end generate_Candidates

/*findMatches takes a dictionary object and a grid object as parameters and outputs the located words. Generate_Candidates is called to create a string vector with all of the possible words found in the grid. Each element of this vector is then passed to the dictionary object function binarySearch. This returns an integer that, if not equal to -1(invalid word), is passed to the dictionary function get_vector to retrieve the word from the dictionary.*/

void findMatches(Dictionary d, Grid g)
{
	vector<string> string = Generate_Candidates(g);
	for (size_t i = 0; i < string.size(); i++)
	{
		int element = d.binarySearch(string[i]);
		if (element != -1) // if the key string is found in the dictionary
		{
			cout << "Found: " << d.get_vector().at(element) << endl;
		} // end if
	} // end for

} // end findMatches

/*void search() initializes a string called filename to be the user input for the grip txt file. A dictionary object is initialized using the dictionary txt file. DictionarySort() is then called to sort the words in the dictionary. User is asked to input a filename for grid. A grid object is initialized with filename from user input. Finally findMatches is called to output the words in the grid that are found in the dictionary.*/

void search(int sort) // same as search()
{
	string filename;
	Dictionary d("dictionary3.txt");
	switch (sort)
	{
	case 0: d.dictionarySort();
		break;
	case 1: d.quickSort(0, (d.get_Dictlength() - 1));
		break;
	case 2: d.heapSort();
		break;
	}
	cout << "Input your grid filename: ";
	cin >> filename;
	Grid g(filename);
	findMatches(d, g);
} // end search

int main()
{
	search(2); //Choose between 0-2 for type of sorting algorithm used
	return 0;
}