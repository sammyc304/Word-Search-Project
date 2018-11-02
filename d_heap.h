//
//  d_heap.hpp
//  EECE2560 3b
//
//
/* This is the header file for the heap class
Also contains class declarations*/

#ifndef HEAP_CLASS
#define HEAP_CLASS

#ifndef NULL
#include <cstddef>
#endif

#include <vector>
#include <cmath>
using namespace std;
template <class T>
class heap
{
public:
	vector<T> vector_heap;
	int heap_size;
	heap(const vector<T>& vector) : vector_heap(vector), heap_size(vector.size())
	{
		vector_heap.insert(vector_heap.begin(), " ");
	}
	int parent(int n);
	int left(int n);
	int right(int n);
	T getItem(int n);
	void exchange(int x, int y);
	void maxHeapify(int i);
	void buildMaxHeap();
	void heapsort();

};

#endif   // HEAP_CLASS

#include <cmath> // needed for floor function
/* The parent function takes a given index of a heap and will return its parent index*/
template <class T>
int heap<T>::parent(int n)
{
	return floor(n / 2);
} // end parent

/* The left function takes a given index of a heap and will return its left child index*/
template <class T>
int heap<T>::left(int n)
{
	return 2 * n;
} // end left

/* The right function takes a given index of a heap and will return its right child index*/
template <class T>
int heap<T>::right(int n)
{
	return (2 * n) + 1;
} // end right

/* The getItem function takes a given index of a heap and will return the object of type T present at this index*/
template <class T>
T heap<T>::getItem(int n)
{
	return vector_heap[n];
} // end getItem

/* The exchange function takes two given indices x and y and will swap the objects in the vector data member at these indices*/
template <class T>
void heap<T>::exchange(int x, int y)
{
	T temp = vector_heap[x];
	vector_heap[x] = vector_heap[y];
	vector_heap[y] = temp;
} // end exchange

/* The maxHeapify function takes an index and checks to see if the children of this index are indeed less than the parent node at index i. If the parent is smaller than either of the children, the larger of the two children is then exchanged with the parent at index i. Then the function is called again with the new parent node.*/
template <class T>
void heap<T>::maxHeapify(int i)
{
	int largest;
	int l = left(i);
	int r = right(i);

	if (l <= heap_size && vector_heap[l] > vector_heap[i])
	{
		largest = l;
	} // end if

	else
	{
		largest = i;
	} // end else

	if (r <= heap_size && vector_heap[r] > vector_heap[largest])
	{
		largest = r;
	} // end if 

	if (largest != i) // that means it is not a max heap
	{
		exchange(i, largest);
		maxHeapify(largest);
	} // end if
} // end maxHeapify()

/* The build max heap function calls maxHeapify() for every parent node of the heap in order to ensure that every child node is lesser than its parent node.*/
template <class T>
void heap<T>::buildMaxHeap()
{
	for (int i = floor(heap_size / 2); i > 0; i--) // starts at last parent node
	{
		maxHeapify(i);
	} // end for

} // end buildMaxHeap()

/* heapsort() utilizes the property of maxHeapify to sort the entire heap*/
template <class T>
void heap<T>::heapsort()
{
	int length = heap_size;
	buildMaxHeap();
	for (int i = length; i > 1; i--)
	{
		exchange(i, 1);
		heap_size--;
		maxHeapify(1);
	}
}