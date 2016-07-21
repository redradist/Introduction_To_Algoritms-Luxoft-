#pragma once

#include <assert.h>
#include <vector>
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

   template<typename TIter>
   TIter partition(TIter b, TIter pivot, TIter e)
   {
      // [b, pivot)[pivot][pivot, e)
      assert(b <= pivot && pivot <= e);

      TIter exchange = b;
      for (TIter pos = b; pos != e, *pos <= *pivot; ++pos)
      {
         assert(*pos <= *pivot);
         exchange = pos;
         assert(*pos <= *pivot);
      }

      if (b != e && exchange != e)
         std::swap(*exchange, *pivot);

      assert(b != e && *std::max(b, exchange) <= *exchange);
      assert(b != e && *std::min(exchange, e) >= *exchange);

      return exchange;
   }

   template<typename TIter>
   void quick_sort(TIter b, TIter e)
   {
      if (e - b <= 1)
         return;

      // TIter pivot = b;
      TIter pivot = partition(b, b + (e - b) / 2, e);
      quick_sort(b, pivot);
      quick_sort(pivot + 1, e);
   }
}

/* namespace heap_sort {

   size_t parent(size_t i)
   {
      return (i - 1) / 2;
   }

   size_t left(size_t i)
   {
      return (2 * i + 1);
   }

   size_t right(size_t i)
   {
      return (2 * i + 2);
   }

   template<typename I>
   void heapify(I *arr, size_t index)
   {
      if (parent(index) < arr[index])
      {

      }

   }

   template<typename T>
   void heap_sort(std::vector<T>& A)
   {
      build_max_heap_down(A);

      // [heap)[sorted)
      auto begin_sorted = A.size();
      while (begin_sorted > 0)
      {
         begin_sorted--;
         swap(A[begin_sorted], A[0]);
         auto heap_size = begin_sorted;
         heapify_down(A, 0, heap_size);
      }
   }
}*/
