//
//  dictionary.hpp
//  EECE2560 3b
//
//
/* This is the header file for the dictionary class which gives the layout for the class*/

#ifndef dictionary_hpp
#define dictionary_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "d_heap.h"
#include <math.h>

using namespace std;

class Dictionary
{
	vector<string> allWords; // vector which contains all the words of the dictionary
	int Dict_length;

public:
	Dictionary(string file);
	string get_word(int x) const;
	vector<string> get_vector();
	friend ostream& operator << (ostream& ostr, const Dictionary& out);
	void dictionarySort();
	void exchange(int x, int y);
	int partition(int p, int r);
	void quickSort(int left, int right);
	void heapSort();
	int binarySearch(string key);
	int get_Dictlength();

};


#endif /* dictionary_hpp */

