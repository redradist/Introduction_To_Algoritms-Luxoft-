#include "SimpleSearch.h"
#include <cassert>

int search_1(int A[], int size, int key)
{
   assert(A != nullptr && size > 0);
	for (int i = 0; i < size; i++)
	{
		if (A[i] == key)
		{
			return i;
		}
	}

	return -1;
}

int search_2(int A[], int size, int key)
{
   assert(A != nullptr && size > 0);
	int i = 0;
	while (i < size)
	{
		if (A[i] == key)
		{
			return i;
		}
		++i;
	}

	return -1;
}

int search_3(int A[], int size, int key)
{
   assert(A != nullptr && size > 0);
	// If enough memory
	A[size] = key;

	int i = 0;
	while (A[i] != key)
		++i;

	if (i != size)
		return i;

	return -1;
}


int search_4(int A[], int size, int key)
{
   assert(A != nullptr && size > 0);
   int last = A[size-1];
   if (last == key)
      return size-1;
   else
      A[size-1] = key;

	int i = 0;
	while (A[i] != key)
		++i;

	if (i != (size-1))
		return i;

	return -1;
}


int binary_search(int A[], int size, int key)
{
   assert(A != nullptr && size > 0);
	int test_index = size / 2 + size % 2 - 1;
	if (A[test_index] == key)
		return test_index;
	else if (size == 1)
		return -1;

   if (A[test_index] < key)
   {
      int result = 
         binary_search(&A[test_index + 1], size - (test_index + 1), key);
      return (result >= 0) ? test_index + 1 + result : result;
   }  
	else
		return binary_search(A, test_index + 1, key);
}

int binary_search_(int A[], int begin, int end, int key)
{
   int size = end - begin;
   assert(A != nullptr && size > 0);
   int test_index = size / 2 + size % 2 + begin - 1;
   if (A[test_index] == key)
      return test_index;
   else if (size == 1)
      return -1;

   if (A[test_index] < key)
      return binary_search_(A, test_index + 1, end, key);
   else
      return binary_search_(A, begin, test_index + 1, key);
}
