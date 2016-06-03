// SequentionSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <assert.h>

extern void sorting(int *A, int size);

int A[] = {1, 33, 56, 0, 23, 5, 34, 4, 9, 2};

int main()
{
	sorting(A, 10);
	std::cout << "Array started: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "  " << A[i] << std::endl;
	}
	std::cout << "Array finished." << std::endl;
    return 0;
}

void sorting(int *A, int size) // Bubble sort
{
	assert(A != nullptr);

	if (size != 0)
	{
		bool sorted;
		do
		{
			sorted = true;
			for (int i = 0; i < (size - 1); i++)
			{
				if (A[i] > A[i + 1])
				{
					sorted = false;
					int temp = A[i + 1];
					A[i + 1] = A[i];
					A[i] = temp;
				}
			}
		} while (!sorted);
	}	
}

template<class TIter>
void sorting_Bubble(TIter b, TIter e) // Bubble sortv alternative
{
	for (TIter pivot = e; pivot != b; --pivot)
	{
		assert(std::is_sorted(pivot, e));
		for (TIter next_i = b+1; next_i < pivot; ++next_i)
		{
			auto i = next_i - 1;
			assert(i == min_element(b, next_i));
			if (*next_i < *i)
				std::swap(*i, *next_i);
			assert(i == min_element(b, next_i));
		}
		assert(std::is_sorted(pivot, e));
	}
}

template<class TIter>
void sort_naive(TIter b, TIter e)
{
	for (int i = b; i < e; ++i)
	{
		for (int j = i+1; j < e; ++j)
		{
			if (*j < *i)
				std::swap(*i, *j);
		}
	}
}

template<class TIter>
TIter min_element(TIter b, TIter e)
{
	TIter result = b;
	while (b < e)
	{
		if (*b < *result)
			result = b;
		++b;
	}
	return result;
}

template<class TIter>
void sort_selection(TIter b, TIter e) // Selection sort O(n^2)
{
	for (TIter pivot = b; pivot < e; ++pivot)
	{
		assert(std::is_sorted(b, pivot));
		auto m = min_element(pivot, e);
		if (pivot != m)			   // O(1)
			std::swap(*pivot, *m); // O(1)
	}
}

template<class TIter>
void sort_selection_fun(TIter b, TIter e) // Selection sort
{
	for (TIter pivot = b; pivot < e; ++pivot)
	{
		assert(std::is_sorted(b, pivot));
		std::swap(*pivot, *min_element(pivot, e));
	}
}

// [b, e) = [sorted)
// [b, e) = [b, p) [pivot, e)

template<class TIter>
void sort_insert(TIter b, TIter e) // Selection sort
{
	for ()
	{
		assert(std::is_sorted(b, pivot));

		// insert pivot to [b, pivot)
		// [b, pivot) = 
		// [b, pivot)[v]
		for (TIter i = pivot; i != b; --i)
		{
			assert(std::is_sorted(b, i) && std::is_sorted(i, pivot+1));
			auto next_i = i + 1;
			if (*next_i < *i)
				std::swap(*i, *next_i);
			else
				break;
			assert(std::is_sorted(b, i) && std::is_sorted(i, pivot + 1));
		}

		assert(std::is_sorted(b, pivot));
	}
}
