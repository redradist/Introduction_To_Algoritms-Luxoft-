// SequentionSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <assert.h>
#include "TestCase.h"
#include "SimpleSearch.h"
#include "SortingMySelf.hpp"
#include "ClassWork.hpp"

int A[] = { 1, 33, 56, 0, 23, 5, 34, 4, 9, 2 };

int main()
{
   hash_map<char, string> M;



   TestCase::checkSearchAlt(binary_search_);
	//PracticeSorting::sort_Bubble(A, A+10);
	//ClassSorting::sort_Merge(A, A + 10, new int[10]);
   int *pivot = &A[3];
   std::cout << "Array item " << *pivot << std::endl;
   PracticeSorting::partition(A, pivot, A + 10);
   for (int i = 0; i < 10; ++i)
   {
      PracticeSorting::partition(A+i, A+i, A + 10);
   }
	std::cout << "Array started: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "  " << A[i] << std::endl;
	}
	std::cout << "Array finished." << std::endl;
	return 0;
}
