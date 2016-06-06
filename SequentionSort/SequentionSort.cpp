// SequentionSort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <assert.h>
#include "SortingMySelf.hpp"
#include "ClassWork.hpp"

int A[] = { 1, 33, 56, 0, 23, 5, 34, 4, 9, 2 };

int main()
{
	PracticeSorting::sort_Bubble(A, A+10);
	std::cout << "Array started: " << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "  " << A[i] << std::endl;
	}
	std::cout << "Array finished." << std::endl;
	return 0;
}
