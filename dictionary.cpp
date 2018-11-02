//
//  dictionary.cpp
//  EECE2560 3b
//
//

#include "dictionary.hpp"

/*The constructor for Dictionary takes a string for the file name of the txt file to be used as the dictionary. All of the words from the txt file are saved in the string vector allWords and Dict_length is incremented each time.*/

Dictionary::Dictionary(string file)
{
	Dict_length = 0;
	ifstream inFile; // initializes a ifstream input file object
	string fileName = file;
	inFile.open(fileName.c_str());  // opens file
	if (!inFile) // error catch if file is not found
	{
		cout << "Cannot open file" << endl;
		exit(0);
	}
	string word;
	while (inFile >> word) // each word in the text file one by one gets stored as word
	{
		allWords.push_back(word); // adds current word to allWords vector
		Dict_length++;
	}
	inFile.close();
} // end constructor

/*get_word takes an integer as a parameter and returns that element from the string vector allWords*/

string Dictionary::get_word(int x) const
{
	return allWords[x];
} // end get_word

/*get_vector returns that private data member allWords(string vector)*/

vector<string> Dictionary::get_vector()
{
	return allWords;
} // end get_vector

/*This overloaded operator allows dictionary objects to output*/

ostream& operator << (ostream& ostr, const Dictionary& out)
{
	for (int i = 0; i < out.Dict_length; i++) // for the length of the dictionary
	{
		cout << out.get_word(i) << "\n"; // prints current word
	} // end for
	return ostr;
} // end overloaded operator <<

/*dictionarySort() uses a selection sort algorithm to order the dictionary in alphabetical order. Starting from zero, if the next string is less(alphabetically) than the first string, the values are switched. This iterates through the entire dictionary.*/

void Dictionary::dictionarySort()
{
	int startScan, minIndex;
	string minValue;

	for (startScan = 0; startScan < (Dict_length - 1); startScan++)
	{
		minIndex = startScan;
		minValue = allWords.at(startScan);
		for (int index = startScan + 1; index < Dict_length; index++)
		{
			if (allWords.at(index) < minValue) // checks to see if the element at current index is less than the current minimum value
			{
				minValue = allWords.at(index); // changes min value and min index
				minIndex = index;
			} // end if
		} // end for
		allWords.at(minIndex) = allWords.at(startScan);
		allWords.at(startScan) = minValue;
	} // end for
} //end dictionarySort

/*exchange takes two indices of allWords and switches their values*/
void Dictionary::exchange(int x, int y)
{
	string temp = allWords[x];
	allWords[x] = allWords[y];
	allWords[y] = temp;
}
/*partition returns an integer index of a vector. The front and back of the vector are passed as parameters. X is set as the initial pivot value. Values lower than the pivot are moved to the left of the pivot and values higher than the pivot are moved to the right. The returned value is the partition used for quickSort*/
int Dictionary::partition(int p, int r)
{
	string x = allWords[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (allWords[j] <= x)
		{
			i++;
			exchange(i, j);
		}
	}
	exchange((i + 1), r);
	return (i + 1);
}
/*quickSort is a recursive function that establishes a partition s using function partition. Then quickSort is called again to the left and right of the partition. And so on.*/
void Dictionary::quickSort(int left, int right)
{
	if (left < right)
	{
		int s = partition(left, right);
		quickSort(left, s - 1);
		quickSort(s + 1, right);
	}
}
/*heapSort creates a heap object of type string and initializes it with the vector, allWords. The heap function heapsort is called on the heap object. The first element of the heap is deleted (because it was a placeholder) and the vector is copied to allWords.*/
void Dictionary::heapSort()
{
	heap<string> Obj_heap(allWords);
	Obj_heap.heapsort();
	Obj_heap.vector_heap.erase(Obj_heap.vector_heap.begin());
	allWords = Obj_heap.vector_heap;
}

/*binarySearch takes a string key as a parameter and returns an integer. This uses a binary search to find if the key is in the string vector and returns the integer element. Starting at the middle, if the middle value equals the key, the key element is returned. If the key is larger, then the second half is searched. If smaller, the first half is searched. And so on. If the word is not found, -1 is returned*/

int Dictionary::binarySearch(string key) // key is what we are searching for
{
	string midValue;
	int mid;
	int first = 0;
	int last = Dict_length - 1;

	while (first <= last)
	{
		mid = floor((first + last) / 2);
		midValue = allWords.at(mid);

		if (key == midValue) // best case, found first try
			return mid;
		else if ((key.compare(midValue)) < 0) // if the key is alphabetically before the mid value
			last = mid - 1;
		else
			first = mid + 1;
	}
	return -1;
}
/*get_Dictlength returns the value of the private data member, Dict_length*/
int Dictionary::get_Dictlength()
{
	return Dict_length;
}