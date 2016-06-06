#ifndef SORTING_MY_SELF
#define SORTING_MY_SELF

#include <assert.h>
#include <algorithm>

namespace PracticeSorting
{
	template<typename TIter>
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

	template<typename TIter>
	TIter max_element(TIter b, TIter e)
	{
		TIter result = b;
		while (b < e)
		{
			if (*b > *result)
				result = b;
			++b;
		}
		return result;
	}

	template<typename TIter>
	void sort_naive(TIter b, TIter e)
	{
		for (TIter i = b; i < e; ++i)
		{
			for (TIter j = i+1; j < e; ++j)
			{
				if (*i > *j)
					std::swap(*i, *j);
			}
		}
	}

	template<typename TIter> // Worked
	void sort_Bubble(TIter b, TIter e)
	{
		for (TIter pivot = e; pivot > b; --pivot)
		{
			assert(std::is_sorted(pivot, e));
			for (TIter next_i = b + 1; next_i < pivot; ++next_i)
			{
				TIter i = next_i - 1;
				assert(pivot > max_element(b, i));
				if (*i > *next_i)
					std::swap(*i, *next_i);
				assert(pivot > max_element(b, i));
			}
			assert(std::is_sorted(pivot, e));
		}
	}

	template<typename TIter> // Worked
	void sort_Selection(TIter b, TIter e)
	{
		for (TIter pivot = b; pivot < e; ++pivot)
		{
			assert(std::is_sorted(pivot, pivot + 1));
			TIter min = min_element(pivot, e);
			if (pivot != min)
				std::swap(*pivot, *min);
			assert(std::is_sorted(pivot, pivot + 1));
		}
	}

	template<typename TIter>  // Worked
	void sort_Insertion(TIter b, TIter e)
	{
		for (TIter pivot = b; pivot < e; ++pivot)
		{
			assert(std::is_sorted(b, pivot));
			for (TIter prev = pivot - 1, insert = pivot; prev >= b; --prev, --insert)
			{
				assert(b == min_element(b, prev));
				if (*prev >= *insert)
					std::swap(*prev, *insert);
				else
					break;
				assert(b == min_element(b, prev));
			}
			assert(std::is_sorted(b, pivot));
		}
	}

	template<typename TIter>
	void sort_Merge(TIter b, TIter e)
	{
		TIter out = new (*TIter)[e-b];
		
	}

	template<typename TIter>
	void merge(TIter b0, TIter e0, TIter b1, TIter e1, TIter out)
	{
		int size = e0 - b0;
		if (size/2 > 1)
		{
			merge(b0, b0 + size / 2, b0 + size / 2, e0, out);
			merge(b1, b1 + size / 2, b1 + size / 2, e1, out + size);
		}
		else
		{
			if (*b0 > *b1)
				*out = *b1;
			else
				*out = *b0;
		}
	}
}

#endif // !SORTING_MY_SELF